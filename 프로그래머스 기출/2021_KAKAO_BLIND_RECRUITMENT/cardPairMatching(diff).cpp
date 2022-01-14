#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

/*2022.01.06
ó���� �ߴ� ����� visit[¦���� ī�� ���� ��Ʈ����ŷ][y][x][���� ã�� �ִ� ī��]�� �̿��ؼ� �����ϰ� bfs�� �а� ����
Ǯ�̿��µ� ��� �κп��� Ʋ������ �߰��� ���ߴ�. bfs�� ������� ���� �˰��� �ƴϰ� �ؼ�..
�Դٰ� �� visit���� ��� ����� ���� Ŀ���� �� �ִٴ� Ȯ���� ������. �����ϸ� �ɰ� ������ �ڵ带 �ϼ��ϴ� ���� �ð��� �ʹ� ���� �� �� ����.
�׷��� �ٸ� ���� �ڵ带 �����ؼ� Ǯ�̹���� �밭 �˰� Ǯ����.*/

struct CARD {
	int y, x, num;
	CARD(int a, int b, int c) {
		num = c; y = a; x = b;
	}
};
vector<CARD> card;
vector<int> v;
vector<string> h;
vector<bool> exst;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void repeatPer(string s, int idx, int dep) {
	if (idx == dep) {
		h.push_back(s);
		return;
	}
	repeatPer(s + '0', idx + 1, dep);
	repeatPer(s + '1', idx + 1, dep);
}
int bfs(vector<vector<int>>& board, int sy, int sx, int ey, int ex) {
	queue<pair<int, pair<int, int>>> q;
	bool visit[4][4] = { false };
	q.push({ 0, {sy, sx} });
	visit[sy][sx] = true;
	while (!q.empty()) {
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		int cdis = q.front().first;
		q.pop();
		if (cy == ey && cx == ex) {
			return cdis;
		}
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			q.push({ cdis + 1, {ny, nx} });
		}
		bool chk = false;
		int ny = cy, nx = cx;
		for (int i = 0; i < 4; i++) {
			while (true) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) break;
				if (board[ny][nx] != -1 && exst[board[ny][nx]]) {
					chk = true;
					break;
				}
			}
			if (!chk) {
				ny -= dy[i];
				nx -= dx[i];
			}
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			q.push({ cdis + 1, {ny, nx} });
		}
	}
}
bool comp(CARD a, CARD b) {
	return a.num < b.num;
}
int solution(vector<vector<int>> board, int r, int c) {
	int answer = 987654321;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0)
				card.push_back(CARD(i, j, board[i][j]));
			else
				board[i][j] = -1;
		}
	}
	exst.resize(card.size(), true);
	sort(card.begin(), card.end(), comp);
	for (int i = 0; i < card.size(); i++) {
		board[card[i].y][card[i].x] = i;
		if (i % 2 == 0) v.push_back(i);
	}
	repeatPer("", 0, card.size() / 2);
	do {
		for (string s : h) {
			int res = 0;
			if (s[0] == '1') {
				res = bfs(board, r, c, card[v[0]].y, card[v[0]].x) + 1;
				exst[v[0]] = false;
			}
			else {
				res = bfs(board, r, c, card[v[0] + 1].y, card[v[0] + 1].x) + 1;
				exst[v[0] + 1] = false;
			}
			for (int i = 0; i < v.size(); i++) {
				int curIdx = 0;
				if (s[i] == '1') curIdx = v[i];
				else curIdx = v[i] + 1;
				int p = (curIdx == v[i]) ? v[i] + 1 : v[i];
				res += bfs(board, card[curIdx].y, card[curIdx].x, card[p].y, card[p].x) + 1;
				exst[p] = false;

				if (i == v.size() - 1)
					break;

				int nextIdx = 0;
				if (s[i + 1] == '1') nextIdx = v[i + 1];
				else nextIdx = v[i + 1] + 1;
				res += bfs(board, card[p].y, card[p].x, card[nextIdx].y, card[nextIdx].x) + 1;
				exst[nextIdx] = false;
			}
			if (answer > res)
				answer = res;
			if (res == 13) {
				for (int i = 0; i < v.size(); i++)
					cout << v[i] << ' ';
				cout << '\n';
				cout << s << '\n';
			}
			for (int i = 0; i < exst.size(); i++)
				exst[i] = true;
		}
	} while (next_permutation(v.begin(), v.end()));
	return answer;
}

int main() {
	cout << solution({ {1, 0, 0, 3}, {2, 0, 0, 0}, {0, 0, 0, 2}, {3, 0, 1, 0} }, 1, 0);
}