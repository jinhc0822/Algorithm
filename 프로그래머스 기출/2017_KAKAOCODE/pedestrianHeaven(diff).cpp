#include <vector>
#include <cstring>
using namespace std;

/*2022.02.22
처음에 bfs인줄 알고 헤매다가 아닌 것을 깨닫고 dp로 풀려고 했는데
풀지 못했다. 3차원 dp를 사용했긴 한데 마지막에 index 초과가 걸리는게 
안될 줄 알았다...
이 풀이에서는 index 초과를 막기 위해 dp 배열의 1, 1을 city_map의 0, 0으로 놓았다.
아니면 그냥 재귀 dp를 써서 내가 생각한대로 풀어볼걸.. 에휴..*/

int MOD = 20170805;
int dp[2][501][501]; // dp[a][b][c]=d : (a, b)에서 c방향으로 진행할 때의 경우의 수는 d

int solution(int m, int n, vector<vector<int>> city_map) {
	memset(dp, 0, sizeof(dp));
	dp[0][1][1] = dp[1][1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (city_map[i - 1][j - 1] == 0) {
				dp[0][i][j] = (dp[0][i][j] + dp[0][i - 1][j] + dp[1][i][j - 1]) % MOD;
				dp[1][i][j] = (dp[1][i][j] + dp[0][i - 1][j] + dp[1][i][j - 1]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1)
				dp[0][i][j] = dp[1][i][j] = 0;
			else {
				dp[0][i][j] = dp[0][i - 1][j] % MOD;
				dp[1][i][j] = dp[1][i][j - 1] % MOD;
			}
		}
	}
	return dp[0][m][n] % MOD;
}