#include <iostream>
using namespace std;

/*2021.12.13
쉬움. 근데 뭔가 그리디보다는 수학 구현에 더 가까운거 같은..*/

int T, ans[3];
const int button[3] = { 300, 60, 10 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	int idx = 0;
	while (true) {
		if (T < button[idx]) {
			if (idx == 2)
				break;
			idx++;
		}
		else {
			T -= button[idx];
			ans[idx]++;
		}
	}
	if (T != 0) cout << -1;
	else {
		for (int i = 0; i < 3; i++)
			cout << ans[i] << ' ';
	}
}