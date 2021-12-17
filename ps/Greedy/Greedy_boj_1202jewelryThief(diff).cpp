#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*2021.12.16
�̷��� ���� ����� �־�����... �� ����� ���� ���� ���ߴ�. 
���� �� ������δ� �ð��ʰ��� �ɸ��µ� multiset�� lower_bound�� ����ϸ� �ȴٴµ�
set�� �� ������� �ʱ⵵ �ؼ� �� �𸣰ڴ�. �� ����� �� ������ ���.*/

int n, k, c[300000];
long long ans;
pair<int, int> jewel[300000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < k; i++)
		cin >> c[i];
	sort(jewel, jewel + n);
	sort(c, c + k);
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && jewel[j].first <= c[i])
			pq.push(jewel[j++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}