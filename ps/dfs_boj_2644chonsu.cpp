#include <iostream>
#include <vector>
#include <cstring>
#define NOTVISIT 123456
using namespace std;

/*2021.11.02 
쉬운 문제*/

int n, m, s, e;
int visit[101];
vector<int> adj[101];

void dfs(int cur) {
	for (int next : adj[cur]) {
		if (visit[next] != NOTVISIT) continue;
		visit[next] = visit[cur] + 1;
		dfs(next);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> e >> m;
	for (int i = 1; i < 101; i++)
		visit[i] = NOTVISIT;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	visit[s] = 0;
	dfs(s);
	if (visit[e] == NOTVISIT) cout << -1;
	else cout << visit[e];
}