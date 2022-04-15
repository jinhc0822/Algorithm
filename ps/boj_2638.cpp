#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

/*2022.04.14
10분컷..*/

int n, m, ans;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool field[100][100];
int exposure[100][100];

void bfs() {
	memset(exposure, 0, sizeof(exposure));
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	exposure[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (field[ny][nx])
				exposure[ny][nx]++;
			else {
				if (exposure[ny][nx] != 0) continue;
				exposure[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
}
void melt() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (exposure[i][j] > 1 && field[i][j])
				field[i][j] = false;
}
bool chk() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j])
				return true;
	return false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> field[i][j];
	while (true) {
		bfs();
		melt();
		ans++;
		if (!chk())
			break;
	}
	cout << ans;
}