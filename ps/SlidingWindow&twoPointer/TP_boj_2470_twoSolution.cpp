#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.09
음.. 흔한 투 포인터 문제 같은데 이분탐색은 왜 들어가 있는지 모르겠다.
방법이 조금 비슷하긴 한데 문제 분류가 되어있을 정도는 아닌거 같은데..*/

int n;
vector<int> sol;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n; sol.resize(n);
	pair<int, int> ans;
	for (int i = 0; i < n; i++)
		cin >> sol[i];
	sort(sol.begin(), sol.end());
	int left = 0, right = n - 1, m = 2000000000;
	while (left < right) {
		int sum = sol[left] + sol[right];
		if (m > abs(sum)) {
			m = abs(sum);
			ans = { sol[left], sol[right] };
			if (sum == 0)
				break;
		}
		if (sum < 0)
			left++;
		else
			right--;
	}
	cout << ans.first << ' ' << ans.second;
}