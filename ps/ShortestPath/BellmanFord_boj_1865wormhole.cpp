#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 501
using namespace std;

/*2021.12.21
최단거리 문제 중 벨만 포드 알고리즘을 써서 푸는 문제이다. 
예전에 풀던 문제인데 틀린 이유를 알지 못한 채로 넘어갔었다. 지금 들어가보니
질문 게시판에 많은 질문이 올라와있는데 그 중 풀이 및 논란 정리를 해놓은 글이 있었다.
아마 내가 전에 풀었던 방법이 그 분이 말한 잘못된 풀이 중 하나인 것 같다. 출발 지점을 1로
했을 경우 1하고 연결되어 있지 않은 정점끼리 음의 사이클을 만들 경우 답이 NO라고 나오기 때문에
틀린 것이다. 왜 이 때는 발견하지 못했을까. 그리고 벨만 포드 알고리즘 코드를 종만북을 참고해
적은 것 같은데 그냥 봤을 때는 모든 정점을 확인하는 것 같지만 실제로 cost를 비교하는 코드에서
둘 다 INF일 경우 계산을 하지 않는 것 같다. 가상의 n+1 정점을 만들어서 모든 정점에 가중치가 0인
간선으로 연결하고 시작점을 n+1 정점으로 하는 방법이 있지만 다른 방법이 뭐가 있는지 궁금하다.*/

int n, m, w;
vector<pair<int, int>> adj[MAX];

bool bellmanFord(int src) {
	vector<int> upper(n + 1, INT_MAX);
	upper[src] = 0;
	bool updated;
	for (int i = 0; i < n; i++) {
		updated = false;
		for (int here = 1; here <= n; here++)
			for (int j = 0; j < adj[here].size(); j++) {
				int there = adj[here][j].first;
				int cost = adj[here][j].second;
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		if (!updated) break;
	}
	if (updated) return false;
	else return true;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, t));
			adj[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, -t));
		}
		bool ans = bellmanFord(1);
		if (ans) cout << "NO" << '\n';
		else cout << "YES" << '\n';
		for (int i = 1; i <= n; i++)
			adj[i].clear();
	}
}