#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

/*2021.12.23
��� �۾����� ���� ���谡 ���ų� �ƴϸ� ���� ���谡 ���� �۾��� ���� �۾��ð��� �� ��쿡 ���ؼ�
ó���� ���ߴ�. ������ �̷��� �ؾ��� �� ���Ƽ� dp�� ���⿡�ٰ� �־��µ� ��Ը¾ҳ�.. 
�ٸ� ����� �� ���� �̷��� �ϴ� �� �´� �� ����. ���� ������ �ణ ������ ����. ����� �ʾ����� �����ؼ� diff�־��.*/

int n, indegree[MAX], t[MAX], dp[MAX], ans;
vector<int> adj[MAX];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int k; cin >> k;
			adj[k].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);
	for (int i = 0; i < n; i++) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < adj[cur].size(); j++) {
			int next = adj[cur][j];
			if (dp[next] < dp[cur] + t[cur])
				dp[next] = dp[cur] + t[cur];
			if (--indegree[next] == 0)
				q.push(next);
		}
		if (i == n - 1) {
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if (ans < dp[j] + t[j])
					ans = dp[j] + t[j];
			}
			cout << ans;
		}
	}
}