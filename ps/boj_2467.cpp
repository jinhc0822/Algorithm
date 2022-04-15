#include <iostream>
using namespace std;

/*2022.04.14
세 용액 문제를 풀고 난 이후라 더 쉽게 풀 수 있었음.*/

int n, fluid[100000], ans[2], m;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> fluid[i];
	m = 2000000000;
	int l = 0, r = n - 1;
	while (l < r) {
		int sum = fluid[l] + fluid[r];
		if (abs(sum) < m) {
			m = abs(sum);
			ans[0] = l;
			ans[1] = r;
		}
		if (sum < 0) l++;
		else r--;
	}
	cout << fluid[ans[0]] << ' ' << fluid[ans[1]];
}