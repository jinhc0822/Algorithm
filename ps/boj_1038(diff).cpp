#include <iostream>
#include <string>
using namespace std;

/*2022.04.08
dp랑 부분합으로 푼 게 너무 아까웠는지 계속 이걸로 풀려고 고집을 너무 부려서 시간이
엄청 오래 걸렸다.. 사실 부분합은 필요없고 dp로만 풀 수 있다. pSum 배열을 딱 한번만
사용하기 때문에...*/

int n, cnt;
int dp[11][10], pSum[11][10]; // dp[i][j] : j로 시작하는 i자리 숫자 중 감소하는 수의 개수
string answer;
bool chk;

void dfs(int d, int num, string s) {
	if (d == 0) {
		cnt++;
		if (cnt >= n) {
			answer = s;
			chk = true;
			return;
		}
		return;
	}
	if (num < d - 1) return;
	for (int i = d - 1; i < num; i++) {
		s.push_back(i + '0');
		dfs(d - 1, i, s);
		s.pop_back();
		if (chk) return;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	if (n >= 1023) {
		cout << -1;
		return 0;
	}
	if (n == 0) {
		cout << 0;
		return 0;
	}
	pSum[1][0] = 1;
	pSum[1][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < 10; i++) {
		dp[1][i] = 1;
		pSum[1][i] = pSum[1][i - 1] + dp[1][i];
	}
	for (int i = 2; i < 11; i++) {
		pSum[i][0] = pSum[i - 1][9];
		for (int j = 1; j < 10; j++) {
			for (int k = j - 1; k >= 0; k--)
				dp[i][j] += dp[i - 1][k];
			pSum[i][j] = pSum[i][j - 1] + dp[i][j];
		}
	}
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 10; j++) {
			if (pSum[i][j] >= n) {
				n -= pSum[i][j - 1];
				string tmp = "";
				tmp.push_back(j + '0');
				dfs(i - 1, j, tmp);
				cout << stoll(answer);
				return 0;
			}
		}
	}
}