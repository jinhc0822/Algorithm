#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*2022.04.20
dp를 써야 풀릴 줄은 몰랐다. 방문한 곳을 다시 방문했을 경우에 바로 무한루프로 봐도 되는지 의문이 처음에 들었다.*/

int n, m, board[50][50];
bool visit[50][50];
int dp[50][50];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m || board[y][x] == 0) return 0;
	if (visit[y][x]) {
		cout << -1;
		exit(0);
	}
	if (dp[y][x] != -1) return dp[y][x];
	visit[y][x] = true;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + (board[y][x] * dy[i]);
		int nx = x + (board[y][x] * dx[i]);
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	visit[y][x] = false;
	return dp[y][x];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') board[i][j] = 0;
			else board[i][j] = s[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
}