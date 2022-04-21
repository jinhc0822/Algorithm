#include <iostream>
#include <algorithm>
using namespace std;

/*2022.04.21
������ �ð��ʰ��� �����ϰŶ� �Ǵ��� ȥ���� ���� ���� �ڵ带 ����. 69�ۼ�Ʈ���� �ð� �ʰ�~
���� ũ�⸦ �������� �����ؼ� ���� ���� ������ ������ ���� ������ �迭�� ���� ���� ���� ���� ������ ������ ����
������ �迭 �̷��� ���� �ذ��Ϸ��� �ߴµ� ���� ��, ���� ������ ���� ������ ���� ������ ����.
+ �ᱹ ���� �ôµ� �׳� ���� ���̶� ���� ���԰� ���� ��쿡 ���� ���� ���� ���� �ϸ� �Ǵ� ��������....
������ �̿��� Ǯ�̰� �ִٰ� �Ѵ�.. */

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