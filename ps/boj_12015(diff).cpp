#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*2022.04.04
몰라서 답을 봤다. 다른 풀이로는 binary search와 segment tree를 이용한 풀이가 있다고 한다.
lowerbound를 이용할 줄은 몰랐네..*/

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, cnt = 0, k; cin >> n;
	vector<int> v;
	v.push_back(INT_MIN);
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k > v.back()) {
			v.push_back(k);
			cnt++;
		}
		else {
			auto low = lower_bound(v.begin(), v.end(), k);
			*low = k;
		}
	}
	cout << cnt;
}