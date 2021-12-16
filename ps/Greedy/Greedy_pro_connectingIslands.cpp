#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.16
크루스칼 알고리즘 사용함.
처음에는 알고리즘 이름은 모르고 어떻게 구현하는지만 기억나서 기억을
되살려 썼는데 union find를 사용해야하는 것을 잊고 있어서 틀림.
최소 스패닝 트리를 구현하는 알고리즘인 크루스칼과 프림 알고리즘은
항상 최소인 간선을 선택한다는 점에서 탐욕적이라 볼 수 있겠다.
종만북에서도 탐욕적으로 선택한다고 되어 있던데 제대로 공부하기 전에는
눈에 띄지 않네..*/

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;
		if (rank[u] == rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int solution(int n, vector<vector<int>> costs) {
	int answer = 0, sz = costs.size();
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < sz; i++)
		edges.push_back(make_pair(costs[i][2], make_pair(costs[i][0], costs[i][1])));
	sort(edges.begin(), edges.end());
	DisjointSet sets(sz + 1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		answer += cost;
	}
    return answer;
}