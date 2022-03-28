#include <iostream>
#include <queue>
using namespace std;

/*2022.03.28
쉬움.*/

struct Info {
	int z;
	int y;
	int x;
	int day;
};
int m, n, h, answer;
int dz[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };
int tomato[100][100][100];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				cin >> tomato[i][j][k];
	queue<Info> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (tomato[i][j][k] == 1)
					q.push({ i, j, k, 0 });
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		answer = cur.day;
		for (int i = 0; i < 6; i++) {
			int nz = cur.z + dz[i];
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) continue;
			if (tomato[nz][ny][nx] == 1 || tomato[nz][ny][nx] == -1) continue;
			tomato[nz][ny][nx] = 1;
			q.push({ nz, ny, nx, cur.day + 1 });
		}
	}
	bool chk = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					chk = false;
					break;
				}
			}
			if (!chk) break;
		}
		if (!chk) break;
	}
	if (!chk) cout << -1;
	else cout << answer;
}