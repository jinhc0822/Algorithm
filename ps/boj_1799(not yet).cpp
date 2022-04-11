#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

/*202.04.11*/

int n, answer;
bool field[10][10], chess[101]; // 1이 비숍을 놓을 수 있는 곳임.
vector<pair<int, int>> bishop;
map<pair<int, int>, int> loc;
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };

bool chk(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dy[i];
			nx += dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
			if (chess[loc[{ny, nx}]]) return false;
		}
	}
	return true;
}
void dfs(int bCnt, int idx) {
	if (idx == bishop.size()) {
		if (bCnt > answer)
			answer = bCnt;
		return;
	}
	for (int i = idx; i < bishop.size(); i++) {
		int y = bishop[i].first;
		int x = bishop[i].second;
		if (!field[y][x]) continue;
		if (!chk(y, x)) continue;
		chess[i] = true;
		dfs(bCnt + 1, i + 1);
		chess[i] = false;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	bishop.push_back({ -1, -1 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
			if (field[i][j]) {
				bishop.push_back({ i, j });
				loc[{i, j}] = bishop.size() - 1;
			}
		}
	}
	dfs(0, 1);
	cout << answer;
}