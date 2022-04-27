#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*2022.04.27*/

struct Door {
	int y;
	int x;
	bool open = false;
};
int t, h, w, ans;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
char building[100][100];
bool keys[26], visit[100][100];
vector<Door> doors[26];

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visit[ny][nx] || building[ny][nx] == '*') continue;
			if (building[ny][nx] >= 'A' && building[ny][nx] <= 'Z') {
				doors[building[ny][nx] - 'A'].push_back({ ny, nx });
				continue;
			}
			visit[ny][nx] = true;
			if (building[ny][nx] == '$') ans++;
			else if (building[ny][nx] != '.') keys[building[ny][nx] - 'a'] = true;
			q.push({ ny, nx });
		}
	}
}
void search(int y, int x) {
	if (visit[y][x]) return;
	char c = building[y][x];
	if (c == '.')
		bfs(y, x);
	else if (c >= 'a' && c <= 'z') {
		keys[c - 'a'] = true;
		bfs(y, x);
	}
	else if (c == '$') {
		ans++;
		bfs(y, x);
	}
	else if (c >= 'A' && c <= 'Z')
		doors[c - 'A'].push_back({ y, x });
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < w; j++)
				building[i][j] = s[j];
		}
		string k; cin >> k;
		for (int i = 0; i < k.size(); i++) {
			if (k == "0") break;
			keys[k[i]] = true;
		}

		for (int i = 0; i < w; i++) {
			search(0, i);
			search(h - 1, i);
		}
		for (int i = 1; i < h - 1; i++) {
			search(i, 0);
			search(i, w - 1);
		}

		bool chk = true;
		while (chk) {
			chk = false;
			for (int i = 0; i < 26; i++) {
				if (!doors[i].empty() && keys[i]) {
					for (int j = 0; j < doors[i].size(); j++) {
						if (!doors[i][j].open) {
							doors[i][j].open = true;
							bfs(doors[i][j].y, doors[i][j].x);
							chk = true;
						}
					}
				}
				if (chk) break;
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < 26; i++)
			doors[i].clear();
		memset(keys, false, sizeof(keys));
		memset(visit, false, sizeof(visit));
	}
}