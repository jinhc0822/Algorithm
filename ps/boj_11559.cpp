#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

/*2022.04.12*/

int chain, cnt;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char field[12][6];
bool visit[12][6];

void dfs(int y, int x, char c) {
	if (cnt >= 4) return;
	visit[y][x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
		if (field[ny][nx] != c || visit[ny][nx]) continue;
		dfs(ny, nx, c);
	}
}
void boom(int y, int x) {
	char c = field[y][x];
	bool v[12][6] = { false, };
	queue<pair<int, int>> q;
	q.push({ y, x });
	v[y][x] = true;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		field[cy][cx] = '.';
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
			if (field[ny][nx] != c || v[ny][nx]) continue;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}
void drop(int c) {
	stack<char> s;
	char res[12];
	for (int i = 0; i < 12; i++) {
		res[i] = '.';
		s.push(field[i][c]);
	}
	int idx = 0;
	while (!s.empty()) {
		if (s.top() != '.')
			res[idx++] = s.top();
		s.pop();
	}
	for (int i = 0; i < 12; i++)
		field[11 - i][c] = res[i];
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 12; i++) {
		string s; cin >> s;
		for (int j = 0; j < 6; j++)
			field[i][j] = s[j];
	}
	while (true) {
		bool chk = false;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (field[i][j] == '.') continue;
				if (visit[i][j]) continue;
				cnt = 0;
				dfs(i, j, field[i][j]);
				if (cnt < 4) continue;
				chk = true;
				boom(i, j);
			}
		}
		if (!chk) break;
		chain++;
		for (int i = 0; i < 6; i++)
			drop(i);
	}
	cout << chain;
}