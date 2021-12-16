#include <iostream>
#include <queue>
using namespace std;

/*2021.12.16
아니ㅋㅋ.. 카드가 1장일때는 비교할 필요가 없다는 사실을 간과했다.
이상하게 헤맸네. 종만북에 비슷한 문제가 있어서 풀이는 쉽게 썼다.*/

int n, ans;
priority_queue<int> cards;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int card; cin >> card;
		cards.push(-card);
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	while (true) {
		int p = -cards.top();
		cards.pop();
		int q = -cards.top();
		cards.pop();
		ans += p + q;
		if (cards.empty())
			break;
		cards.push(-(p + q));
	}
	cout << ans;
}