#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*2022.04.09*/

int n, m;
bool plane[100][100];
int res[100][100];
bool visit[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void bfs(int cnt) {
	queue<pair<int, int>> q;
	memset(visit, false, sizeof(visit));
	visit[0][0] = true;
	q.push({ 0, 0 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			if (!plane[ny][nx])
				q.push({ ny, nx });
			else {
				res[ny][nx] = cnt;
				plane[ny][nx] = false;
			}
		}
	}
}
bool chk() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (plane[i][j])
				return true;
	return false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> plane[i][j];
	if (!chk()) {
		cout << 0 << '\n' << 0;
		return 0;
	}
	int resT = 0, resCnt = 0;
	while (chk())
		bfs(++resT);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (res[i][j] == resT)
				resCnt++;
	cout << resT << '\n' << resCnt;
}