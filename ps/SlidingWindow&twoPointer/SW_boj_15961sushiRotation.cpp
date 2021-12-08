#include <iostream>
#include <vector>
using namespace std;

/*2021.12.08
처음 푸는 슬라이딩 윈도우 문제라 감 잡기가 조금은 어려웠는데
그냥 저냥 풀만했다. 근데 이렇게 푸는거 맞는지 모르겠네. */

int n, d, k, c;
vector<int> dish;
int eat[3001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dish.push_back(a);
	}
	for (int i = 0; i < n; i++)
		dish.push_back(dish[i]);
	int start = 0, end = k - 1, ans = 0;
	for (int i = start; i <= end; i++) {
		if (eat[dish[i]] == 0) ans++;
		eat[dish[i]]++;;
	}
	if (eat[c] == 0) ans++;
	eat[c]++;
	start++; end++;
	int cnt = ans;
	while (start < n) {
		if ((--eat[dish[start - 1]]) == 0) cnt--;
		if ((eat[dish[end]]++) == 0) cnt++;
		if (cnt > ans) ans = cnt;
		start++; end++;
	}
	cout << ans;
}