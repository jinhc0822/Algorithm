#include <vector>
#include <queue>
using namespace std;

/*2022.03.02
다익스트라 문제*/

int solution(int N, vector<vector<int>> road, int K) {
	int dist[51], answer = 0;
	vector<vector<pair<int, int>>> adj(N + 1);
	for (int i = 0; i < road.size(); i++) {
		adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
		adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
	}
	for (int i = 1; i <= N; i++)
		dist[i] = 987654321;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nCost = adj[cur][i].second;
			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if (dist[i] <= K)
			answer++;
	return answer;
}