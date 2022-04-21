#include <iostream>
#include <algorithm>
using namespace std;

/*2022.04.21
무조건 시간초과가 문제일거라 판단해 혼신의 힘을 다한 코드를 제출. 69퍼센트에서 시간 초과~
공을 크기를 기준으로 정렬해서 전에 나온 공들의 무게의 합을 저장한 배열과 색깔 별로 전에 나온 공들의 무게의 합을
저장한 배열 이렇게 만들어서 해결하려고 했는데 같은 색, 같은 무게의 공을 저장할 때에 문제가 생김.
+ 결국 답을 봤는데 그냥 이전 공이랑 색과 무게가 같을 경우에 이전 공과 같은 답을 하면 되는 문제였다....
스택을 이용한 풀이가 있다고 한다.. */

int n, ans[200000], C[200000], W[2001];
pair<pair<int, int>, int> balls[200000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c, w; cin >> c >> w;
		balls[i] = { {w, c - 1}, i };
	}
	sort(balls, balls + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int idx = balls[i].second;
		int w = balls[i].first.first;
		int c = balls[i].first.second;
		C[c] += w;
		W[w] += w;
		sum += w;
		ans[idx] = sum - C[c] - W[w] + w;
		if (i != 0 && w == balls[i - 1].first.first && c == balls[i - 1].first.second)
			ans[idx] = ans[balls[i - 1].second];
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}