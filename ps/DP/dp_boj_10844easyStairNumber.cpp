#include <iostream>
#define MOD 1000000000
using namespace std;

/*2021.11.29
예전에 풀었던 문제. 규칙 찾느라 애를 먹었던 기억이 난다.
지금 풀 때는 반복적 dp가 아닌 재귀적으로 풀었다. 
시간은 얼마 안 걸렸지만 MOD 조건을 깜빡해서 한 번 틀렸다.*/

int n;
int cache[101][10];

int stair(int len, int cur) {
	if (len == 1) return cache[len][cur] = 1;
	int& ret = cache[len][cur];
	if (ret != -1) return ret;

	if (cur == 0) ret = stair(len - 1, cur + 1);
	else if (cur == 9) ret = stair(len - 1, cur - 1);
	else ret = stair(len - 1, cur - 1) + stair(len - 1, cur + 1);

	return ret %= MOD;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 10; j++)
			cache[i][j] = -1;
	int ans = 0;
	for (int i = 1; i < 10; i++)
		ans = (ans + stair(n, i)) % MOD;
	cout << ans;
}