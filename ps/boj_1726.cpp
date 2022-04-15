#include <iostream>
#include <queue>
using namespace std;

/*2022.04.14
쉬움.*/

struct Info {
	int y;
	int x;
	int dir;
};
int m, n;
Info s, e;
int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };
int turnDir[2][5] = { { -1, 4, 3, 1, 2 }, { -1, 3, 4, 2, 1 } };
bool factory[100][100];
bool visit[100][100][5];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> factory[i][j];
	cin >> s.y >> s.x >> s.dir;
	s.y--; s.x--;
	cin >> e.y >> e.x >> e.dir;
	e.y--; e.x--;
	queue<pair<Info, int>> q;
	q.push({ s, 0 });
	visit[s.y][s.x][s.dir] = true;
	while (!q.empty()) {
		int cy = q.front().first.y;
		int cx = q.front().first.x;
		int cDir = q.front().first.dir;
		int cmd = q.front().second;
		q.pop();
		if (cy == e.y && cx == e.x && cDir == e.dir) {
			cout << cmd;
			break;
		}
		for (int i = 0; i < 2; i++) {
			int nDir = turnDir[i][cDir];
			if (visit[cy][cx][nDir]) continue;
			visit[cy][cx][nDir] = true;
			q.push({ {cy, cx, nDir}, cmd + 1 });
		}
		for (int i = 1; i <= 3; i++) {
			int ny = cy + dy[cDir] * i;
			int nx = cx + dx[cDir] * i;
			if (ny < 0 || nx < 0 || ny >= m || nx >= n || factory[ny][nx]) break;
			if (visit[ny][nx][cDir]) continue;
			visit[cy][cx][cDir] = true;
			q.push({ {ny, nx, cDir}, cmd + 1 });
		}
	}
}