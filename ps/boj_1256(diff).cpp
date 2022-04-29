#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000100
using namespace std;

/*2022.04.22
dfs로 풀려고 했지만 역시 단순하게 풀면 당연히 시간초과가 걸림.
사실 종만북에서 매우 유사한 문제를 본 기억이 있다..*/

int n, m, k;
int dp[201][101];

void bino(int a, int z) {
	for (int i = 0; i <= n + m; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i && j <= m; j++)
			dp[i][j] = min(INF, dp[i - 1][j - 1] + dp[i - 1][j]);
		if (i <= m) dp[i][i] = 1;
	}
}
string getWord(int a, int z, int skip) {
	if (a == 0) return string(z, 'z');
	if (z == 0) return string(a, 'a');
	if (skip < 0) {
		cout << -1;
		exit(0);
	}
	if (skip < dp[a + z - 1][a - 1])
		return "a" + getWord(a - 1, z, skip);
	return "z" + getWord(a, z - 1, skip - dp[a + z - 1][a - 1]);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	bino(n, m);
	cout << getWord(n, m, k - 1);
}