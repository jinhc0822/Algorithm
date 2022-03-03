#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*2022.03.03
고민을 조금 많이했다.
처음에는 일단 간선이 하나뿐인 정점에서 부모 정점으로 숫자 올려주고
그 간선은 지우고 이런 식으로 했는데 시간초과가 났다.
그래서 방법은 똑같은데 시간초과가 나지 않는 코드를 생각해낸게 이건데
배열들이 많아서 조금 난잡하긴 하다. 근데 뭐.. 내걸아 비슷한 답들이 조금 보이긴하네.*/

long long answer;
int maxDepth;
vector<bool> visit;
vector<long long> v;
vector<int> parent;
vector<vector<int>> adj, d;

void makeTree(int cur, int p, int depth) {
	visit[cur] = true;
	parent[cur] = p;
	d[depth].push_back(cur);
	if (depth > maxDepth)
		maxDepth = depth;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (visit[adj[cur][i]]) continue;
		makeTree(adj[cur][i], cur, depth + 1);
	}
}
long long solution(vector<int> a, vector<vector<int>> edges) {
	visit.assign(a.size(), false);
	adj.resize(a.size());
	d.resize(a.size());
	parent.resize(a.size());
	for (int i = 0; i < a.size(); i++)
		v.push_back(a[i]);
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	makeTree(0, 0, 0);
	for (int i = maxDepth; i > 0; i--) {
		for (int j = 0; j < d[i].size(); j++) {
			v[parent[d[i][j]]] += v[d[i][j]];
			answer += abs(v[d[i][j]]);
		}
	}
	if (v[0] == 0)
		return answer;
	else
		return -1;
}
int main() {
	solution({ -5, 0, 2, 1, 2 }, { {0, 1}, {3, 4}, {2, 3}, {0, 3} });
}