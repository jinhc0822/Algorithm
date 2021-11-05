#include <iostream>
#include <queue>
using namespace std;

/*2021.11.04
반례를 찾지 못해 결국 반례 힌트를 보았다.
예전에도 이런 문제를 본 적이 있는 것 같다..

최단거리를 찾기 위해서 꼭 거쳐야하는 칸을 a라고 하자. a칸에서 (n, m)까지 가기 위해서는 벽을 하나 부숴야 한다.
그리고 a에 도달하는 서로 다른 두 경로를 A, B라고 하자. A가 이전에 벽을 부순 경로이고 B는 그렇지 않은 경로이다.
탐색이 시작되고 bfs를 돌다 보니 a칸에는 경로 A가 먼저 도착했다. 따라서 visit[a]가 true가 되어 경로 B에서는 a칸에 도달할 수 없다.
그래서 정답이 증가한 값이 되거나 없다고 나오는 것이다.

이 문제를 해결하기 위해서 visit을 3차원 배열로 만들었다. 벽을 이미 부순 경로가 도착했을 때와 
부수지 않은 경로가 도착했을 때를 다르게 확인하는 것이다.

지금처럼 (부순 적이 있는 경로/아직 한 번도 안 부순 경로) 2가지 이상의 상태가 있는 문제는 visit을 3차원 이상으로 만들어야할 것 같다.*/

struct Info {
	int x, y;
	bool isBreak;
	int dis;
	Info(int a, int b, int c, bool d) {
		y = a;
		x = b;
		dis = c;
		isBreak = d;
	}
};

int n, m; 
bool map[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool visit[1001][1001][2];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j + 1] = s[j] - '0';
	}
	int ans = 987654321;
	queue <Info> q;
	q.push(Info(1, 1, 1, false));
	visit[1][1][0] = true;
	visit[1][1][1] = true;
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cdis = q.front().dis;
		bool cb = q.front().isBreak;
		q.pop();
		if (cy == n && cx == m) {
			if (cdis < ans)
				ans = cdis;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
			if ((cb && visit[ny][nx][1]) || (!cb && visit[ny][nx][0])) continue;
			if (map[ny][nx]) {
				if (cb) continue;
				else {
					visit[ny][nx][0] = true;
					visit[ny][nx][1] = true;
					q.push(Info(ny, nx, cdis + 1, true));
				}
			}
			else {
				visit[ny][nx][cb] = true;
				q.push(Info(ny, nx, cdis + 1, cb));
			}
		}
	}
	if (ans == 987654321) cout << -1;
	else cout << ans;
}