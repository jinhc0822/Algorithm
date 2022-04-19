#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

/*2022.04.19
이분탐색을 왜 계속 생각 못할까..*/

long long ans = LLONG_MAX;
int n, m, t[100000];

bool can(long long T) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += T / t[i];
		if (sum > m)
			break;
	}
	if (sum >= m) return true;
	else return false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t, t + n);
	long long left = 0, right = 1e18, mid;
	right++;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		if (can(mid)) {
			if (ans > mid)
				ans = mid;
			right = mid;
		}
		else
			left = mid;
	}
	cout << ans;
}