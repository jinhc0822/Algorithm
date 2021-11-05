#include <iostream>
#include <queue>
using namespace std;

/*2021.11.05
2206번 벽 부수고 이동하기 시리즈와 매우 비슷한 문제.
거의 똑같다고 봐도 무방하다.*/

struct Monkey {
	int y, x;
	int dis, horseMove;
	Monkey(int a, int b, int c, int d) {
		y = a;
		x = b;
		dis = c;
		horseMove = d;
	}
};
int k, w, h;
bool map[200][200];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int hdy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int hdx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool visit[200][200][31];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];
	queue<Monkey> q;
	visit[0][0][k] = true;
	q.push(Monkey(0, 0, 0, k));
	while (!q.empty()) {
		int cy = q.front().y;
		int cx = q.front().x;
		int cdis = q.front().dis;
		int cLeftMove = q.front().horseMove;
		q.pop();
		if (cy == h - 1 && cx == w - 1) {
			cout << cdis;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visit[ny][nx][cLeftMove] || map[ny][nx]) continue;
			visit[ny][nx][cLeftMove] = true;
			q.push(Monkey(ny, nx, cdis + 1, cLeftMove));
		}
		if (cLeftMove == 0) continue;
		for (int i = 0; i < 8; i++) {
			int ny = cy + hdy[i];
			int nx = cx + hdx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visit[ny][nx][cLeftMove - 1] || map[ny][nx]) continue;
			visit[ny][nx][cLeftMove - 1] = true;
			q.push(Monkey(ny, nx, cdis + 1, cLeftMove - 1));
		}
	}
	cout << -1;
}