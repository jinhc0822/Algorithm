#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*2021.11.04-05
첫번째 제출이랑 완전히 다른 방향으로 코드를 짰는데 틀렸다. 
반례를 생각해보니 water 배열이 S 표시 된 곳은 방문하지 않는다는 것이 문제였다.
그리고 이미 물에 잠긴 지역은 큐에 넣지 않기 위해 curTime+1보다 같을 때가 아니라
작거나 같을 시에 큐에 넣지 않는다 라고 바꿔주었고 그로 인해 water 배열을 
초기화할 때 -1이던 것을 엄청 큰 수로 바꿔주었다.*/

int r, c, sy, sx, ey, ex, t;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char map[50][50];
bool visit[50][50];
int water[50][50];

void waterMove() {
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < r; i++) // 1차 수정 부분
		for (int j = 0; j < c; j++)
			water[i][j] = 987654321; //여기까지
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == '*') {
				q.push(make_pair(0, make_pair(i, j)));
				visit[i][j] = true;
				water[i][j] = 0;
			}
	while (!q.empty()) {
		int curT = q.front().first;
		int curY = q.front().second.first;
		int curX = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx]) continue;
			if (map[ny][nx] == 'X' || map[ny][nx] == 'D') continue; // 1차 수정 부분
			visit[ny][nx] = true;
			water[ny][nx] = curT + 1;
			q.push(make_pair(curT + 1, make_pair(ny, nx)));
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
			if (s[j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (s[j] == 'D') {
				ey = i;
				ex = j;
			}
		}
	}
	waterMove();
	memset(visit, false, sizeof(visit));
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(sy, sx)));
	visit[sy][sx] = true;
	while (!q.empty()) {
		int curTime = q.front().first;
		int curY = q.front().second.first;
		int curX = q.front().second.second;
		q.pop();
		if (curY == ey && curX == ex) {
			cout << curTime;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx]) continue;
			if (map[ny][nx] == '*' || map[ny][nx] == 'X') continue;
			if (water[ny][nx] <= curTime + 1) continue; // 1차 수정 부분
			visit[ny][nx] = true;
			q.push(make_pair(curTime + 1, make_pair(ny, nx)));
		}
	}
	cout << "KAKTUS";
}