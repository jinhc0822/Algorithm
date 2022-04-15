#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.04.15
좀 헷갈린다고 생각했는데 생각보다 수월하게 맞춤..*/

int n, dp[2][100000];
vector<int> num;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	num.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	dp[0][0] = num[0];
	dp[1][0] = num[0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = max(num[i], dp[0][i - 1] + num[i]);
		dp[1][i] = max({ num[i], dp[0][i - 1], dp[1][i - 1] + num[i] });
	}
	int ans = -2000000001;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			if (ans < dp[i][j])
				ans = dp[i][j];
	cout << ans;
}