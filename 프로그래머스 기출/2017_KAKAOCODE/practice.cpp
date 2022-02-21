#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*2022.02.21
뻔한 문제인데 이상한 방향으로 풀고 있었네ㅋㅋ;*/

int MOD = 20170805;
bool visit[2][500][500];
int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	queue<pair<pair<int, int>, int>> q;
	memset(visit, false, sizeof(visit));
	q.push(make_pair(make_pair(0, 1), 1));
	q.push(make_pair(make_pair(1, 0), 0));
	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int dir = q.front().second;// dir가 0이면 위에서 오던 차, 1이면 왼쪽에서 오던 차
		int state = city_map[cy][cx];
		q.pop();
		if (cy == m - 1 && cx == n - 1) {
			answer++;
			answer %= MOD;
		}
		for (int i = 0; i < 2; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (city_map[ny][nx] == 1) continue;
			if (state == 2)
				if (dir != i)
					continue;
			q.push(make_pair(make_pair(ny, nx), i));
		}
	}
	return answer;
}