#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.20
Ǯ�̴� ���� �����س´µ� �˸��� container�� ã���� �ð��� �� �ɷȴ�.
listó�� ����, ������ ����鼭 [] ������ �Ǵ� container�� ���°ɱ�..*/

int n, m, ans;
vector<int> wLimit, w;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	wLimit.resize(n);
	for (int i = 0; i < n; i++)
		cin >> wLimit[i];
	cin >> m;
	w.resize(m);
	for (int i = 0; i < m; i++)
		cin >> w[i];
	sort(wLimit.begin(), wLimit.end(), greater<>());
	sort(w.begin(), w.end(), greater<>());
	while (!w.empty()) {
		bool chk = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < w.size();) {
				if (wLimit[i] >= w[j]) {
					chk = true;
					w.erase(w.begin() + j);
					break;
				}
				else
					j++;
			}
		}
		ans++;
		if (w.empty()) {
			cout << ans;
			return 0;
		}
		if (!chk) {
			cout << -1;
			return 0;
		}
	}
}