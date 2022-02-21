#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*2022.02.21
쉬움. 근데 괜히 전역변수 쓸 때 본함수 안에서 초기화해달란 말이 있는게 아니었네ㅋㅋ 안하니 틀림*/

bool visit[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int bfs(int y, int x, int m, int n, vector<vector<int>>& picture) {
	int color = picture[y][x];
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visit[y][x] = true;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (visit[ny][nx]) continue;
			if (picture[ny][nx] != color) continue;
			visit[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
	return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && picture[i][j] != 0) {
				int k = bfs(i, j, m, n, picture);
				if (k > max_size_of_one_area)
					max_size_of_one_area = k;
				number_of_area++;
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}