#include <iostream>
#include <queue>
using namespace std;

/*2022.04.04
아... 메모리 초과 계속 걸려서 어떻게 풀지 몰랐는데.. 답은 엄청 단순했다.
next로 들어갈 때 visit을 체크해주는게 아니라 pop하고 바로 다음에 visit을 체크해주는
것이 방법이었다..*/

int n, k, minT, cnt;
bool visit[200002];

int move(int cur, int type) {
	switch (type) {
	case 1:
		return cur - 1;
	case 2:
		return cur + 1;
	case 3:
		return cur * 2;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int t = q.front().second;
		q.pop();
		visit[cur] = true;
		if (cnt > 0 && n == k && t == minT) cnt++;
		if (cnt == 0 && cur == k) {
			minT = t;
			cnt++;
		}
		for (int i = 1; i <= 3; i++) {
			int next = move(cur, i);
			if (next < 0 || next > 200000) continue;
			if (visit[next]) continue;
			q.push({ next, t + 1 });
		}
	}
	cout << minT << '\n' << cnt;
}