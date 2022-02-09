#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*2022.02.07
처음 봤을 때는 턴 번호로 visit을 3차원으로 만들면 되나 싶었는데
그럼 상대가 최적의 선택을 한다는 보장이 없기 때문에 막혀서 답을 봤다.
일단 공식 해설에서는 a함수, b함수로 나눠서 하는 것으로 풀이되어 있는데 인터넷에서는 대부분 이렇게 풀이했더라.
공식 해설에서처럼 2개의 함수가 교차로 재귀하는 것은 종만북에서 본 거 같기도 하고...
minimax 알고리즘을 알고 있다면 푸는 데 도움이 된다고 한다.

+ 상당히 이해하기 어렵다.누가 이기고 누가 지는지 확실하게 알 수 없는 상황에서
문제 해결을 할 수 없는 것처럼 보인다. 이기는 경우의 수가 있을 때 최소이동값을
반환하고 없을 경우 최대이동값을 반환한다.
다음에 다시 보고 이해해보자...*/

int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
bool isFinish(vector<vector<int>>& board, int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (inRange(ny, nx) && board[ny][nx])
			return false;
	}
	return true;
}
//y1, x1은 지금 차례인 사람의 좌표.
pair<bool, int> solve(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
	if (isFinish(board, y1, x1))
		return { false, 0 };
	if (y1 == y2 && x1 == x2)
		return { true, 1 };

	bool canWin = false;
	int minTurn = 1e9, maxTurn = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y1 + dy[i];
		int nx = x1 + dx[i];
		if (!inRange(ny, nx) || !board[ny][nx]) continue;
		board[y1][x1] = 0;
		pair<bool, int> res = solve(board, y2, x2, ny, nx);
		board[y1][x1] = 1;
		// 상대방이 다음턴 이후의 결과가 패배일 때(= 이번턴 이후의 내 결과는 승리)
		if (!res.first) {
			canWin = true;
			minTurn = min(minTurn, res.second);
		}
		// 상대방이 다음턴 이후의 결과가 승리일 때,
		// 지금 턴에서 이전의 모든 경우의 수에서 내가 졌을 경우
		else if (!canWin) {
			maxTurn = max(maxTurn, res.second);
		}
	}
	int turn = canWin ? minTurn : maxTurn;
	return { canWin, turn + 1 };
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	n = board.size(), m = board[0].size();
	return solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}

int main() {
	cout << solution({ {1, 1, 1}, {1, 1, 1}, {1, 1, 1} }, { 1, 0 }, { 1, 2 });
}