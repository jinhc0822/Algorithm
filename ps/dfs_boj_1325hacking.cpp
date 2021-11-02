#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*2021.11.02
���� ������ �׷������� �˾ҳ�.. �Ҹ�����. 
�ٵ� �ð��� �� �̷��� ���� �ɷ�����
�ٵ� �ٸ� ��� �ڵ� �ð��� ���� ���� ����ϴ�.*/

int n, m, M, sum;
bool visit[10001];
vector<int> adj[10001];
vector<pair<int, int>> ans;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}
void dfs(int cur) {
	sum++;
	for (int next : adj[cur]) {
		if (visit[next]) continue;
		visit[next] = true;
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
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		sum = 0;
		dfs(i);
		ans.push_back(make_pair(sum, i));
	}
	sort(ans.begin(), ans.end(), comp);
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0)
			if (ans[i].first != ans[i - 1].first)
				break;
		cout << ans[i].second << ' ';
	}
}