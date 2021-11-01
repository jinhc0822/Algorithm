#include <iostream>
#include <vector>
using namespace std;

/*10분만에 푼 기본적인 문제*/

int n, m;
bool visit[101];
vector<int> adj[101];

void dfs(int cur) {
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (visit[next]) continue;
		dfs(next);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (visit[i])
			ans++;
	cout << ans - 1;
}