#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

/*2021.12.23
모든 작업들이 선행 관계가 없거나 아니면 선행 관계가 없는 작업이 가장 작업시간이 긴 경우에 대해서
처리를 못했다. 느낌상 이렇게 해야할 거 같아서 dp를 저기에다가 넣었는데 어떻게맞았네.. 
다른 사람들 답 보니 이렇게 하는 게 맞는 것 같다. 같이 섞여서 약간 생소한 문제. 어렵진 않았지만 생소해서 diff넣어둠.*/

int n, indegree[MAX], t[MAX], dp[MAX], ans;
vector<int> adj[MAX];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int k; cin >> k;
			adj[k].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < adj[cur].size(); j++) {
			int next = adj[cur][j];
			if (dp[next] < dp[cur] + t[cur])
				dp[next] = dp[cur] + t[cur];
			if (--indegree[next] == 0)
				q.push(next);
		}
		if (i == n - 1) {
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if (ans < dp[j] + t[j])
					ans = dp[j] + t[j];
			}
			cout << ans;
		}
	}
}