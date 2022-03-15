#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

/*2022.03.15
bfs와 최소 스패닝 트리를 이용해서 풀었다.
너무 변수들이 많아서 약간 헷갈려서 조금 오래 걸리긴 했는데 그래도 나름 잘 푼 것 같다.
*/

int n, landNum[300][300], cnt;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool visit[300][300];
vector<int> adj[90001];
map<pair<int, int>, int> road;

void bfs(int y, int x, int num, vector<vector<int>>& land, int h, bool chk) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;
	if (!chk) landNum[y][x] = num;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			int diff = abs(land[cy][cx] - land[ny][nx]);
			if (diff > h) {
				if (chk) {
					int cur = landNum[cy][cx];
					int next = landNum[ny][nx];
					if (cur == next) continue;
					if (road[{cur, next}] == 0) {
						adj[cur].push_back(next);
						road[{cur, next}] = diff;
					}
					else if (road[{cur, next}] > diff)
						road[{cur, next}] = diff;
					else
						continue;
				}
				else continue;
			}
			if (visit[ny][nx]) continue;
			visit[ny][nx] = true;
			if (!chk) landNum[ny][nx] = num;
			q.push({ ny, nx });
		}
	}
}
int prim() {
	int answer = 0;
	vector<bool> v(cnt + 1);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < adj[1].size(); i++)
		pq.push({ -road[{1, adj[1][i]}], adj[1][i] });
	v[1] = true;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (!v[cur]) {
			v[cur] = true;
			answer += dist;
			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				int nDist = road[{cur, next}];
				if (!v[next])
					pq.push({ -nDist, next });
			}
		}
	}
	return answer;
}
int solution(vector<vector<int>> land, int height) {
	n = land.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visit[i][j])
				bfs(i, j, ++cnt, land, height, false);
	vector<bool> v(cnt + 1);
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!v[landNum[i][j]]) {
				v[landNum[i][j]] = true;
				bfs(i, j, 0, land, height, true);
			}
	return prim();
}