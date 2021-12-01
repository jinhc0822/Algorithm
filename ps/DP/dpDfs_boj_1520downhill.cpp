#include <iostream>
#include <cstring>
using namespace std;

/*2021.11.30
그렇게 어려운 문제는 아닌데 왜 북마크를 해놨는지 생각해보니 시간초과 때문이었다.*/

int n, m, map[500][500];
int cache[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool visit[500][500];

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visit[ny][nx]) continue;
		if (map[y][x] <= map[ny][nx]) continue;
		visit[ny][nx] = true;
		ret += dfs(ny, nx);
		visit[ny][nx] = false;
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	memset(cache, -1, sizeof(cache));
	cout << dfs(0, 0);
}