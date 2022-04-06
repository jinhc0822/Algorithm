#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/*2022.04.06
꽤 오랜시간을 투자했는데 계속 AC를 받지 못했다. 그 코드들은 어디가 문제였던걸까? 반례를 찾지 못하겠다... 50퍼 정도에서
계속 틀리던데.. 그래서 일단 결국 답지를 봤다. 내 코드는 메모리초과 전까지의 코드이다.
다익스트라에서 이차원배열을 사용하는 것은 처음 본 것 같다... 조건이 이렇게 두 개 있을 때는 dfs나 bfs에서 visit을 이차원
배열을 사용하는 것처럼 배열의 차원을 높여야 할 것 같다. dp[i][j] : 시작점 1에서 i까지 가는데 비용 j로 가는 최소 시간*/

struct Info {
	int arrival;
	int cost;
	int time;
};
int t, n, m, k;
int dist[101][10001];
vector<vector<Info>> adj;

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {1, 0} });
	dist[1][0] = 0;
	while (!pq.empty()) {
		int cTime = -pq.top().first;
		int cur = pq.top().second.first;
		int cCost = pq.top().second.second;
		pq.pop();
		if (dist[cur][cCost] < cTime) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].arrival;
			int nCost = cCost + adj[cur][i].cost;
			int nTime = cTime + adj[cur][i].time;
			if (nCost <= m && nTime < dist[next][nCost]) {
				for (int j = nCost + 1; j <= m; j++) {
					if (dist[next][j] <= nTime) break;
					dist[next][j] = nTime;
				}
				dist[next][nCost] = nTime;
				pq.push({ -nTime, {next, nCost} });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dist[i][j] = INF;
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v, c, d });
		}
		dijkstra();
		int answer = INF;
		for (int i = 0; i <= m; i++)
			if (dist[n][i] < answer)
				answer = dist[n][i];
		if (answer == INF) cout << "Poor KCM" << '\n';
		else cout << answer << '\n';
	}
}