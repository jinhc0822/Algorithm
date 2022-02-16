#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*2022.02.14
인접리스트를 이용한 bfs라고 볼 수 있으므로 최대 정점이 25개 간선이 1200개이므로 완전탐색으로 될 것이라고 판단했다.
근데 이거 왜 안풀리는지; visit을 3차원으로 푸는 것까지는 잘했는데 왜 뜬금없이 테케 반이나 틀리는지 잘 모르겠다.
엥?.. 갑자기 되네.. q에 처음 넣는 값을 (0, 0)으로 해서 dir을 -1로 하지 않고 아에 (0, 1), (1, 0)을 따로 넣었는데
이것만 살짝 바꿨는데 갑자기 돌아간다. 왜인지는 잘 모르겠다.*/

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
	sz = board.size();
	queue<Info> q;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			for (int k = 0; k < 4; k++)
				visit[i][j][k] = 2e9;
	q.push({ 0, 0, -1, 0 });
	visit[0][0][0] = visit[0][0][1] = visit[0][0][2] = visit[0][0][3] = 0;
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		if (cur.y == sz - 1 && cur.x == sz - 1)
			continue;
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= sz || nx >= sz || board[ny][nx] == 1) continue;
			int nCost = (cur.dir == -1 || i == cur.dir) ? cur.cost + 100 : cur.cost + 600;
			if (visit[ny][nx][i] < nCost) continue;
			visit[ny][nx][i] = nCost;
			q.push({ ny, nx, i, nCost });
		}
	}
	return min(visit[sz - 1][sz - 1][1], visit[sz - 1][sz - 1][3]);
}