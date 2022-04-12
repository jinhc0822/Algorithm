#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*202.04.11
일단 처음에는 가장 일반적인 방법으로 한 위치에 비숍을 놓았을 경우 대각선에 전부 놓을 수 없음 표시를 하는 방법을
사용했는데 시간초과. 비숍을 놓을 위치를 정해서 그 위치에 대각선으로 놓인 다른 비숍이 있는지 확인하는 방법도 시간초과.
질문에서 힌트를 얻었다. 예전에 체스할 때 한번 생각해본 적 있는 부분이었는데ㅋㅋ.. 참.. 생각해보지 못한
풀이였다...*/

int n, res;
bool field[10][10]; // 1이 비숍을 놓을 수 있는 곳임.
int cField[10][10]; // 0이 비숍을 놓을 수 있는 곳임.
vector<pair<int, int>> bishopB, bishopW;
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };

void f(int y, int x, bool b) {
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dy[i];
			nx += dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
			if (b) cField[ny][nx]++;
			else cField[ny][nx]--;
		}
	}
}
void dfs(int bCnt, int idx, vector<pair<int, int>>& bishop) {
	if (idx == bishop.size()) {
		if (bCnt > res)
			res = bCnt;
		return;
	}
	for (int i = idx; i < bishop.size(); i++) {
		int y = bishop[i].first;
		int x = bishop[i].second;
		if (!field[y][x] || cField[y][x] > 0) continue;
		cField[y][x] = 1;
		f(y, x, true);
		dfs(bCnt + 1, i + 1, bishop);
		cField[y][x] = 0;
		f(y, x, false);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j]) {
				if ((i + j) % 2 == 1)
					bishopB.push_back({ i, j });
				else
					bishopW.push_back({ i, j });
			}
		}
	}
	int answer = 0;
	dfs(0, 0, bishopB);
	answer = res;
	res = 0;
	dfs(0, 0, bishopW);
	answer += res;
	cout << answer;
}