#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*2022.02.14
인접리스트로 푼 bfs와 동일하기 때문에 정점 개수 최대 625개, 간선 개수 1200개 해서
시간복잡도가 1825가 나와 완전탐색을 해도 되겠다고 판단했다.
아니 사람들이 다 틀리던 25번은 맞는데 왜 중간중간 틀리지?.. 뭐가 틀린지 모르겠다.
*/

struct Info {
	int y;
	int x;
	int dir;
	int cost;
};
int sz;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visit[25][25][4];

int solution(vector<vector<int>> board) {
	int answer = 2e9;
	sz = board.size();
	queue<Info> q;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			for (int k = 0; k < 4; k++)
				visit[i][j][k] = 2e9;
	q.push({ 1, 0, 1, 100 });
	q.push({ 0, 1, 3, 100 });
	visit[0][0][0] = 0;
	visit[0][0][2] = 0;
	visit[0][1][3] = 100;
	visit[1][0][1] = 100;
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		if (cur.y == sz - 1 && cur.x == sz - 1)
			continue;
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= sz || nx >= sz) continue;
			if (board[ny][nx] == 1) continue;
			int nCost = (i == cur.dir) ? cur.cost + 100 : cur.cost + 600;
			if (visit[ny][nx][i] < nCost) continue;
			visit[ny][nx][i] = nCost;
			q.push({ ny, nx, i, nCost });
		}
	}
	return min(visit[sz - 1][sz - 1][1], visit[sz - 1][sz - 1][3]);
}

int main() {
	cout << solution({ {0, 0, 0, 0, 0, 0, 0, 0},{1, 0, 1, 1, 1, 1, 1, 0},
		{1, 0, 0, 1, 0, 0, 0, 0},{1, 1, 0, 0, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 0, 0, 0 }, {1, 1, 1, 1, 1, 1, 1, 0},
		{ 1, 1, 1, 1, 1, 1, 1, 0 }, {1, 1, 1, 1, 1, 1, 1, 0} });
}