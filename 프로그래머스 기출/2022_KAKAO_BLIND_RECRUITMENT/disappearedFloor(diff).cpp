#include <vector>
#include <algorithm>
using namespace std;

/*2022.02.07
처음 봤을 때는 턴 번호로 visit을 3차원으로 만들면 되나 싶었는데
그럼 상대가 최적의 선택을 한다는 보장이 없기 때문에 막혀서 답을 봤다.
일단 공식 해설에서는 a함수, b함수로 나눠서 하는 것으로 풀이되어 있는데 인터넷에서는 대부분 이렇게 풀이했더라.
공식 해설에서처럼 2개의 함수가 교차로 재귀하는 것은 종만북에서 본 거 같기도 하고...
minimax 알고리즘을 알고 있다면 푸는 데 도움이 된다고 한다.*/

int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
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
		if (!res.first) {
			canWin = true;
			minTurn = min(minTurn, res.second);
		}
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