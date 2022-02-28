#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*2022.02.24
구상까지는 쉬웠는데 함정이 조금 있었네.. 알파벳 순서를 맞추기 위해서 매칭되는 카드를 찾았을 경우
break를 해서 다시 알파벳 처음으로 돌아가야한다는 것과 visit을 3차원 배열로 해야한다는 점을
처음에는 생각을 못했다.*/


struct Info {
	int y;
	int x;
	int dir;
	bool corner;
};
bool visit[4][100][100];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M;

bool bfs(int y, int x, vector<string>& board) {
	memset(visit, false, sizeof(visit));
	queue<Info> q;
	q.push({ y, x, -1, true });
	visit[0][y][x] = visit[1][y][x] = visit[2][y][x] = visit[3][y][x] = true;
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
			if (visit[i][ny][nx] || (board[ny][nx] != '.' && board[ny][nx] != board[y][x])) continue;
			if (!cur.corner && i != cur.dir) continue;
			visit[i][ny][nx] = true;
			if (cur.dir == -1 || i == cur.dir)
				q.push({ ny, nx, i, cur.corner });
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
				break;
			}
		}
		if (!chk)
			return "IMPOSSIBLE";
		if (cnt == tot)
			return answer;
	}
}