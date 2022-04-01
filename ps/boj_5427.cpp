#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

/*2022.04.01
괜히 질문에 25퍼에서 막힌다고 한게 아니네.. 나도 처음에 한 번 틀렸다. fire 초기화를
안 해줬기 때문이기도 하고 중간에 코드 짤 때는 fireMove가 -1인지 아닌지 확인해줘야할까
생각했는데 필요 없을 것이라고 생각했던게 잘못됐었다... 그 외에는 어렵진 않다.*/

int t, w, h;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
pair<int, int> start;
char building[1000][1000];
int fireMove[1000][1000];
bool visit[1000][1000];
vector<pair<int, int>> fire;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> w >> h;
		fire.clear();
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				building[i][j] = s[j];
				if (building[i][j] == '@')
					start = { i, j };
				else if (building[i][j] == '*')
					fire.push_back({ i, j });
			}
		}
		memset(fireMove, -1, sizeof(fireMove));
		memset(visit, false, sizeof(visit));
		queue<pair<int, pair<int, int>>> q;
		for (int i = 0; i < fire.size(); i++) {
			q.push({ 0, {fire[i].first, fire[i].second} });
			fireMove[fire[i].first][fire[i].second] = 0;
		}
		while (!q.empty()) {
			int y = q.front().second.first;
			int x = q.front().second.second;
			int t = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (fireMove[ny][nx] != -1) continue;
				if (building[ny][nx] == '#') continue;
				fireMove[ny][nx] = t + 1;
				q.push({ t + 1, {ny, nx} });
			}
		}
		q.push({ 0, {start.first, start.second} });
		visit[start.first][start.second] = true;
		bool chk = false;
		while (!q.empty()) {
			int y = q.front().second.first;
			int x = q.front().second.second;
			int t = q.front().first;
			q.pop();
			if (y == 0 || x == 0 || y == h - 1 || x == w - 1) {
				chk = true;
				cout << t + 1 << '\n';
				break;
			}
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (visit[ny][nx] || building[ny][nx] != '.') continue;
				if (fireMove[ny][nx] != -1 && fireMove[ny][nx] <= t + 1) continue;
				visit[ny][nx] = true;
				q.push({ t + 1, {ny, nx} });
			}
		}
		if (!chk) cout << "IMPOSSIBLE" << '\n';
	}
}