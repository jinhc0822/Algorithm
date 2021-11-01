#include <iostream>
#include <cstring>
using namespace std;

/*10분 걸림. 근데 난 행을 y, 열은 x를 사용하는데 
여기는 반대로 적혀있어서 순간 멈칫했음...*/

int m, n, k, ans;
bool map[50][50];
bool visit[50][50];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (!map[ny][nx] || visit[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--) {
		memset(visit, false, sizeof(visit));
		memset(map, false, sizeof(map));
		ans = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			map[b][a] = true;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visit[i][j] && map[i][j]) {
					dfs(i, j);
					ans++;
				}
		cout << ans << '\n';
	}
}