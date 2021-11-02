#include <iostream>
#include <cstring>
using namespace std;

/*2021.11.02
쉬웠음. 처음엔 시간초과 걸릴까봐 걱정했는데 빙산의 칸의 개수를 제한한 거 보니 
구현만 하면 잘 될거 같았음. 정답률이 왜 25%일까..*/

int n, m, cnt, ans;
int iceCopy[300][300], iceberg[300][300];
bool visit[300][300];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visit[ny][nx] || iceberg[ny][nx] == 0) continue;
		dfs(ny, nx);
	}
}
void c() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			iceCopy[i][j] = iceberg[i][j];
}
void melt() {
	c();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int zeros = 0;
			for (int k = 0; k < 4; k++)
				if (iceCopy[i + dy[k]][j + dx[k]] == 0)
					zeros++;
			iceberg[i][j] -= zeros;
			if (iceberg[i][j] < 0) 
				iceberg[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> iceberg[i][j];
	while (true) {
		ans++;
		melt();
		memset(visit, false, sizeof(visit));
		cnt = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (iceberg[i][j] > 0 && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
		if (cnt > 1) {
			cout << ans;
			return 0;
		}
		if (cnt == 0) break;
	}
	cout << 0;
}