#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*2022.04.22
dfs로 풀려고 했지만 역시 단순하게 풀면 당연히 시간초과가 걸림.
사실 종만북에서 매우 유사한 문제를 본 기억이 있다..*/

int n, m, k, cnt;
int dp[101][101];

int dfs(int a, int z) {
	if (a == 0 || z == 0) return 1;
	int& ret = dp[a][z];
	if (ret != -1) return ret;
	ret = min(dfs(a - 1, z) + dfs(a, z - 1), 1000000001);
	return ret;
}
void getWord() {

}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	dfs(n, m);

}