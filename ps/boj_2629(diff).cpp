#include <iostream>
using namespace std;

/*2022.04.18
첫 시도는 실패. 그 이유는 같은 무게를 재도 그 무게를 만드는데 사용한 추가 다를 수 있기
때문. 이를 해결하기 위해 map을 사용하기로 했다. map을 사용할 경우 시간초과나 메모리초과
떠서 패스..
배낭 문제를 푼지 너무 오래돼서...*/

int n, p[30], m, b[7];
bool dp[31][15001]; // dp[i][j] : i번까지의 추를 사용했을 경우 j 무게를 만들 수 있는가?

void dfs(int idx, int w) {
	if (idx > n || dp[idx][w]) return;
	dp[idx][w] = true;
	dfs(idx + 1, w + p[idx]);
	dfs(idx + 1, abs(w - p[idx]));
	dfs(idx + 1, w);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	dfs(0, 0);
	for (int i = 0; i < m; i++) {
		if (b[i] > 15000) cout << 'N' << ' ';
		else if (dp[n][b[i]]) cout << 'Y' << ' ';
		else cout << 'N' << ' ';
	}
}