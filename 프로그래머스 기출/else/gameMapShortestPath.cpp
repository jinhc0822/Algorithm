#include <vector>
#include <queue>
using namespace std;

/*2022.03.02*/

int solution(vector<vector<int>> maps) {
	int n = maps.size();
	int m = maps[0].size();
	int dy[4] = { -1 ,1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visit[0][0] = true;
	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		if (cy == n - 1 && cx == m - 1)
			return dist;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visit[ny][nx] || maps[ny][nx] == 0) continue;
			visit[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), dist + 1));
		}
	}
	return -1;
}