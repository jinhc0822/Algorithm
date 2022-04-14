#include <iostream>
#include <algorithm>
using namespace std;

/*2022.04.11
투 포인터와 이분탐색을 생각하긴 했지만 정확한 풀이를 잘 몰랐다. 한 인덱스를 고정하고 하는 방법이 있을 줄이야..
근데 이분탐색은 사실 나는 생각만 하고 방법을 찾지 못했는데 이분탐색은 어떻게 풀이하는 걸까*/

int n, ans[3];
long long m;
long long fluid[5000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	m = 3000000000;
	for (int i = 0; i < n; i++)
		cin >> fluid[i];
	sort(fluid, fluid + n);
	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			long long sum = fluid[i] + fluid[l] + fluid[r];
			if (abs(sum) < m) {
				m = abs(sum);
				ans[0] = i;
				ans[1] = l;
				ans[2] = r;
			}
			if (sum < 0)
				l++;
			else
				r--;
		}
	}
	cout << fluid[ans[0]] << ' ' << fluid[ans[1]] << ' ' << fluid[ans[2]];
}