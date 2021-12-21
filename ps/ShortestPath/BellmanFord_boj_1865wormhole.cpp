#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 501
using namespace std;

/*2021.12.21
�ִܰŸ� ���� �� ���� ���� �˰����� �Ἥ Ǫ�� �����̴�. 
������ Ǯ�� �����ε� Ʋ�� ������ ���� ���� ä�� �Ѿ����. ���� ������
���� �Խ��ǿ� ���� ������ �ö���ִµ� �� �� Ǯ�� �� ��� ������ �س��� ���� �־���.
�Ƹ� ���� ���� Ǯ���� ����� �� ���� ���� �߸��� Ǯ�� �� �ϳ��� �� ����. ��� ������ 1��
���� ��� 1�ϰ� ����Ǿ� ���� ���� �������� ���� ����Ŭ�� ���� ��� ���� NO��� ������ ������
Ʋ�� ���̴�. �� �� ���� �߰����� ��������. �׸��� ���� ���� �˰��� �ڵ带 �������� ������
���� �� ������ �׳� ���� ���� ��� ������ Ȯ���ϴ� �� ������ ������ cost�� ���ϴ� �ڵ忡��
�� �� INF�� ��� ����� ���� �ʴ� �� ����. ������ n+1 ������ ���� ��� ������ ����ġ�� 0��
�������� �����ϰ� �������� n+1 �������� �ϴ� ����� ������ �ٸ� ����� ���� �ִ��� �ñ��ϴ�.*/

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