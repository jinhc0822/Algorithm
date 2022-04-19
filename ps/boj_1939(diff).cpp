#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*2022.04.05
발상을 떠올리는 것은 쉬웠다. 하지만 아직 이분탐색을 제대로 사용하지 못하는 것 같다.
마지막에 mid를 출력하는 것으로 했더니 틀리고 left를 출력하는 것으로 하니 맞았다.
https://www.acmicpc.net/blog/view/109 여기에 잘 정리되어 있는 것 같다. 항상 이게 좀 헷갈리더라.
+ 근데 left와 right 사이에 하나의 정수가 들어가는지 판단하는 것이기 때문에 left값과 right값은 포함되지 않는다. 주의해서 사용.*/

int n, m, s, e;
bool visit[10001], num[10001];
vector<pair<int, int>> adj[10001];

bool bfs(int w) {
	queue<int> q;
	memset(visit, false, sizeof(visit));
	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == e)
			return true;
		for (auto k : adj[cur]) {
			int next = k.first;
			int cost = k.second;
			if (visit[next]) continue;
			if (!num[next]) continue;
			if (cost < w) continue;
			visit[next] = true;
			q.push(next);
		}
	}
	return false;
}
void dfs(int cur) {
	num[cur] = true;
	for (auto k : adj[cur]) {
		int next = k.first;
		if (num[next]) continue;
		dfs(next);
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> s >> e;
	dfs(s);
	int left = 1, right = 1000000001;
	int mid = (left + right) / 2;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (!bfs(mid)) right = mid;
		else left = mid;
	}
	cout << left;
}