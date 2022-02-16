#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*2022.02.14
��������Ʈ�� �̿��� bfs��� �� �� �����Ƿ� �ִ� ������ 25�� ������ 1200���̹Ƿ� ����Ž������ �� ���̶�� �Ǵ��ߴ�.
�ٵ� �̰� �� ��Ǯ������; visit�� 3�������� Ǫ�� �ͱ����� ���ߴµ� �� ��ݾ��� ���� ���̳� Ʋ������ �� �𸣰ڴ�.
��?.. ���ڱ� �ǳ�.. q�� ó�� �ִ� ���� (0, 0)���� �ؼ� dir�� -1�� ���� �ʰ� �ƿ� (0, 1), (1, 0)�� ���� �־��µ�
�̰͸� ��¦ �ٲ�µ� ���ڱ� ���ư���. �������� �� �𸣰ڴ�.*/

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