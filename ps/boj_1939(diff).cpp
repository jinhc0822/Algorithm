#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*2022.04.05
�߻��� ���ø��� ���� ������. ������ ���� �̺�Ž���� ����� ������� ���ϴ� �� ����.
�������� mid�� ����ϴ� ������ �ߴ��� Ʋ���� left�� ����ϴ� ������ �ϴ� �¾Ҵ�.
https://www.acmicpc.net/blog/view/109 ���⿡ �� �����Ǿ� �ִ� �� ����. �׻� �̰� �� �򰥸�����.
+ �ٵ� left�� right ���̿� �ϳ��� ������ ������ �Ǵ��ϴ� ���̱� ������ left���� right���� ���Ե��� �ʴ´�. �����ؼ� ���.*/

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