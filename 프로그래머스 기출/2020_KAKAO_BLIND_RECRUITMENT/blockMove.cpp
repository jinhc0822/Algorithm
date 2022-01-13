#include <vector>
#include <queue>
using namespace std;

/*2022.01.13
엄청 어렵진 않았다. 회전을 할 경우에 dy, dx 같이 배열을 사용해서 간편하게 할 수 없을까 생각하다가
rotation 배열을 만들었다. 나쁘지 않은 방법이었던 것 같다.*/

struct Drone {
	int y, x;
	int dis, dir; // dir은 (y, x)를 기준으로 어느 방향으로 드론이 뻗어있는가 이다. 0123 순서로 상하좌우 
	Drone(int a, int b, int c, int d) {
		y = a; x = b; dis = c; dir = d;
	}
	bool chk(int k) {
		if (y == k && x == k - 1 && dir == 3)
			return true;
		if (y == k - 1 && x == k && dir == 1)
			return true;
		if (y == k && x == k && dir == 0)
			return true;
		if (y == k && x == k && dir == 2)
			return true;
		return false;
	}
};
bool visit[101][101][4];
bool B[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int opp[4] = { 1, 0, 3, 2 };
int rotation[4][2] = { {2, 3}, {2, 3}, {0, 1}, {0, 1} };

int solution(vector<vector<int>> board) {
	int answer = 0;
	int sz = board.size();
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			B[i + 1][j + 1] = board[i][j];
	queue<Drone> q;
	q.push(Drone(1, 1, 0, 3));
	visit[1][1][3] = true;
	visit[1][2][2] = true;
	while (!q.empty()) {
		Drone drone = q.front();
		q.pop();
		if (drone.chk(sz)) {
			answer = drone.dis;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = drone.y + dy[i];
			int nx = drone.x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > sz || nx > sz) continue;
			if (ny + dy[drone.dir] <= 0 || nx + dx[drone.dir] <= 0 || ny + dy[drone.dir] > sz || nx + dx[drone.dir] > sz) continue;
			if (visit[ny][nx][drone.dir]) continue;
			if (B[ny][nx] || B[ny + dy[drone.dir]][nx + dx[drone.dir]]) continue;
			visit[ny][nx][drone.dir] = true;
			visit[ny + dy[drone.dir]][nx + dx[drone.dir]][opp[drone.dir]] = true;
			q.push(Drone(ny, nx, drone.dis + 1, drone.dir));
		}
		for (int i = 0; i < 2; i++) {
			int ndir = rotation[drone.dir][i];
			int chky = drone.y + dy[drone.dir] + dy[ndir];
			int chkx = drone.x + dx[drone.dir] + dx[ndir];
			if (chky <= 0 || chkx <= 0 || chky > sz || chkx > sz) continue;
			if (B[chky][chkx]) continue;
			if (visit[drone.y][drone.x][ndir]) continue;
			if (B[drone.y + dy[ndir]][drone.x + dx[ndir]]) continue;
			visit[drone.y][drone.x][ndir] = true;
			visit[drone.y + dy[ndir]][drone.x + dx[ndir]][opp[ndir]] = true;
			q.push(Drone(drone.y, drone.x, drone.dis + 1, ndir));
		}
		int cy = drone.y + dy[drone.dir];
		int cx = drone.x + dx[drone.dir];
		int cdir = opp[drone.dir];
		for (int i = 0; i < 2; i++) {
			int ndir = rotation[cdir][i];
			int chky = cy + dy[cdir] + dy[ndir];
			int chkx = cx + dx[cdir] + dx[ndir];
			if (chky <= 0 || chkx <= 0 || chky > sz || chkx > sz) continue;
			if (B[chky][chkx]) continue;
			if (visit[cy][cx][ndir]) continue;
			if (B[cy + dy[ndir]][cx + dx[ndir]]) continue;
			visit[cy][cx][ndir] = true;
			visit[cy + dy[ndir]][cx + dx[ndir]][opp[ndir]] = true;
			q.push(Drone(cy, cx, drone.dis + 1, ndir));
		}
	}
	return answer;
}