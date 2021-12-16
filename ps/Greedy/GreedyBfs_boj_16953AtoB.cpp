#include <iostream>
#include <queue>
using namespace std;

/*2021.12.16
음.. bfs 문제가 greedy에 나올줄 몰랐네.. long long 타입 때문에 한 번 틀림. 
k * 10 + 1에서 그냥 자동으로 캐스팅 될줄 알았는데 k의 타입 따라가나봄..*/

int a, b;
queue<pair<long long, int>> q;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	q.push({ a, 0 });
	while (!q.empty()) {
		long long k = q.front().first;
		int d = q.front().second;
		q.pop();
		if (k == b) {
			cout << d + 1;
			return 0;
		}
		if (2 * k <= b)
			q.push({ 2 * k, d + 1 });
		if (k * 10 + 1 <= b)
			q.push({ k * 10 + 1, d + 1 });
	}
	cout << -1;
}