#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*2022.02.24*/

struct Info {
	int y;
	int x;
	int dir;
	bool corner;
};
bool visit[100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M;

bool bfs(int y, int x, vector<string>& board) {
	memset(visit, false, sizeof(visit));
	queue<Info> q;
	q.push({ y, x, -1, true });
	visit[y][x] = true;
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		if (cur.dir != -1 && board[cur.y][cur.x] == board[y][x]) {
			board[y][x] = '.';
			board[cur.y][cur.x] = '.';
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visit[ny][nx] || (board[ny][nx] != '.' && board[ny][nx] != board[y][x])) continue;
			if (!cur.corner && i != cur.dir) continue;
			visit[ny][nx] = true;
			if (cur.dir == -1 || i == cur.dir)
				q.push({ ny, nx, i, true });
			else if (i != cur.dir)
				q.push({ ny, nx, i, false });
		}
	}
	return false;
}
string solution(int m, int n, vector<string> board) {
	string answer = "";
	N = m; M = n;
	int tot = 0, cnt = 0;
	bool alphabet[26] = { false, };
	pair<int, int> loc[26];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
				alphabet[board[i][j] - 'A'] = true;
				loc[board[i][j] - 'A'] = { i, j };
				tot++;
			}
	tot /= 2;
	while (true) {
		bool chk = false;
		for (int i = 0; i < 26; i++) {
			if (!alphabet[i])
				continue;
			if (bfs(loc[i].first, loc[i].second, board)) {
				answer += (i + 'A');
				chk = true;
				cnt++;
				alphabet[i] = false;
			}
		}
		if (!chk)
			return "IMPOSSIBLE";
		if (cnt == tot)
			return answer;
	}
}