#include <iostream>
#include <queue>
using namespace std;

/*2022.05.02
쉬움.*/

int n, m, go[101];
bool visit[101];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b; cin >> a >> b;
		go[a] = b;
	}
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visit[1] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == 100) {
			cout << cnt;
			break;
		}
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next > 100) continue;
			if (visit[next]) continue;
			visit[next] = true;
			bool chk = true;
			while (go[next] != 0) {
				next = go[next];
				if (visit[next]) {
					chk = false;
					break;
				}
				visit[next] = true;
			}
			if (chk)
				q.push({ next, cnt + 1 });
		}
	}
}