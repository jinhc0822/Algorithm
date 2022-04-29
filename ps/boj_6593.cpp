#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*2022.04.28
쉬움. 출력에 마침표를 안 적어서 조금 틀렸음..*/

struct Loc {
	int z;
	int y;
	int x;
};
int l, r, c;
char building[30][30][30];
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
bool visit[30][30][30];
Loc s, e;

int bfs() {
	queue<pair<Loc, int>> q;
	visit[s.z][s.y][s.x] = true;
	q.push({ s, 0 });
	while (!q.empty()) {
		int z = q.front().first.z;
		int y = q.front().first.y;
		int x = q.front().first.x;
		int t = q.front().second;
		q.pop();
		if (z == e.z && y == e.y && x == e.x)
			return t;
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
			if (visit[nz][ny][nx] || building[nz][ny][nx] == '#') continue;
			visit[nz][ny][nx] = true;
			q.push({ {nz, ny, nx}, t + 1 });
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				string str; cin >> str;
				for (int k = 0; k < c; k++) {
					building[i][j][k] = str[k];
					if (building[i][j][k] == 'S')
						s = { i, j, k };
					else if (building[i][j][k] == 'E')
						e = { i, j, k };
				}
			}		
		}
		int ans = bfs();
		if (ans == -1) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << ans << " minute(s)." << '\n';
	}
}