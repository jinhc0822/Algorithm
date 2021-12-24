#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*2021.12.22
기본적인 위상정렬 문제이다.*/

int n, m;
int indegree[1001];
vector<int> order[100];
vector<int> adj[1001];

vector<int> topologySort() {
	vector<int> res;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			res.clear();
			break;
		}
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (int j = 0; j < adj[cur].size(); j++) {
			int next = adj[cur][j];
			if (--indegree[next] == 0)
				q.push(next);
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		for (int j = 0; j < t; j++) {
			int s; cin >> s;
			order[i].push_back(s);
			if (j != 0)
				indegree[s]++;
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < order[i].size() - 1; j++)
			adj[order[i][j]].push_back(order[i][j + 1]);
	vector<int> ans = topologySort();
	if (ans.empty()) 
		cout << 0;
	else
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << '\n';
}