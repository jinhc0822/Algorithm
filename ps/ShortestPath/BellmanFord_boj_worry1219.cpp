#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
#define INF 1000000000000000
using namespace std;

/*2021.12.22
��... ���� ã��� �ʹ� �����.. �ϴ� �ִ��� ���ؾ��ϱ⿡ ���ÿ��� �� �� �ִ� ���� ������ �ߴ�.
�׸��� ��������� �������� �� �� ���� ��츦 dfs�� ����ؼ� �ذ��߰� �� �� ���� ���带 ����ߴµ� 
���� ����Ŭ�� �����Ѵٰ� �ؼ� ������ ���� ���Ѵ�� �Ҹ� �� �ִ� ���� �ƴ϶� �� ����Ŭ����
�������� �� �� �ִ����� üũ�� ������ϱ� ������ �������� �ڵ� �ȿ� dfs�� �־���. �׸��� 
n�� 100�̰� �� ���õ��� ���� ����Ŭ�� �̷� �ÿ� int���� �ִ��� ���� ���� �ֱ� ������ upper ����
long long���� ����߸� �Ѵ�. 100���� ���ð� ����Ŭ�� �̷� ��츦 ������ ���ߴ�...*/

int n, s, e, m, money[MAX], earn;
bool visit[MAX];
vector<pair<int, int>> road[MAX];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < road[x].size(); i++) {
		int next = road[x][i].first;
		if (visit[next]) continue;
		dfs(next);
	}
}
vector<long long> bellmanFord(int src) {
	vector<long long> upper(n, INF);
	upper[src] = money[src];
	bool updated;
	for (int i = 0; i < n; i++) {
		updated = false;
		for (int here = 0; here < n; here++) {
			if (upper[here] == INF) continue;
			for (int j = 0; j < road[here].size(); j++) {
				int there = road[here][j].first;
				int cost = road[here][j].second;
				if (upper[there] > upper[here] + cost + money[there]) {
					upper[there] = upper[here] + cost + money[there];
					updated = true;
					if (i == n - 1) {
						memset(visit, false, sizeof(visit));
						dfs(here);
						if (visit[e]) {
							upper.clear();
							return upper;
						}
					}
				}
			}
		}
		if (!updated) break;
	}
	return upper;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		money[i] = -a;
	}
	dfs(s);
	if (!visit[e]) {
		cout << "gg";
		return 0;
	}
	vector<long long> res = bellmanFord(s);
	if (res.empty()) cout << "Gee";
	else cout << -res[e];
}