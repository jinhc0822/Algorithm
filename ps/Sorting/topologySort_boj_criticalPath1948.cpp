#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

/*2021.12.27
dp를 2056번 문제에서 사용한 것이 도움이 되었다. 어렵진 않았지만
visit city 배열이 필요함을 깨닫지 못해 한 번 틀렸다.*/

int n, m, s, e, cnt;
int indegree[MAX], dp[MAX];
bool city[MAX];
vector<pair<int, int>> adj[MAX], adjRev[MAX];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		indegree[E]++;
		adj[S].push_back(make_pair(E, T));
		adjRev[E].push_back(make_pair(S, T));
	}
	cin >> s >> e;
	queue<int> q;
	q.push(s);
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < adj[cur].size(); j++) {
			int next = adj[cur][j].first;
			if (dp[next] < dp[cur] + adj[cur][j].second)
				dp[next] = dp[cur] + adj[cur][j].second;
			if (--indegree[next] == 0)
				q.push(next);
		}
	}
	cout << dp[e] << '\n';
	q.push(e);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < adjRev[cur].size(); j++) {
			int next = adjRev[cur][j].first;
			if (dp[next] != dp[cur] - adjRev[cur][j].second)
				continue;
			cnt++;
			if (!city[next]) {
				city[next] = true;
				q.push(next);
			}
		}
	}
	cout << cnt;
}