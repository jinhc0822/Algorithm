#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*2021.12.16
이렇게 쉬운 방법이 있었구나... 이 방법은 정말 생각 못했다. 
내가 한 방법으로는 시간초과가 걸리는데 multiset의 lower_bound를 사용하면 된다는데
set을 잘 사용하지 않기도 해서 잘 모르겠다. 이 방법이 더 마음에 든다.*/

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