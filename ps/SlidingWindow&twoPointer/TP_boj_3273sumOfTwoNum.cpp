#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.09
쉬움.*/

int n, x;
vector<int> a;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> x;
	sort(a.begin(), a.end());
	int left = 0, right = n - 1, cnt = 0;
	while (left < right) {
		int sum = a[left] + a[right];
		if (sum == x) {
			cnt++;
			left++;
			right--;
		}
		else if (sum < x)
			left++;
		else
			right--;
	}
	cout << cnt;
}