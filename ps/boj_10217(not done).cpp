#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*2022.04.06*/

struct Info {
	int arrival;
	int cost;
	int time;
};
int t, n, m, k;
pair<int, int> dist[101];
vector<Info> adj[101];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			dist[i] = { 987654321, 987654321 };
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v, c, d });
			adj[v].push_back({ u, c, d });
		}
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, 1 });
		dist[1] = { 0, 0 };
		while (!pq.empty()) {
			int cTime = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i].arrival;
				int nCost = adj[cur][i].cost;
				int nTime = adj[cur][i].time;
				if (dist[next].first > cTime + nTime && dist[next].second > dist[cur].second + nCost
					&& dist[cur].second + nCost <= m) {
					dist[next] = { cTime + nTime, dist[cur].second + nCost };
					pq.push({ -dist[next].first, next });
				}
			}
		}
		if (dist[n].first == 987654321)
			cout << "Poor KCM" << '\n';
		else
			cout << dist[n].first << '\n';
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
}