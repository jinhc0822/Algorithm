#include <string>
#include <map>
using namespace std;

/*2022.03.02
visit을 4차원으로 만들어서 풀었다.*/

bool visit[11][11][11][11] = { false };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int solution(string dirs) {
	map<char, int> direction;
	direction['U'] = 0;
	direction['D'] = 1;
	direction['R'] = 2;
	direction['L'] = 3;
	int answer = 0;
	pair<int, int> cur = { 5, 5 };
	for (int i = 0; i < dirs.size(); i++) {
		int ndir = direction[dirs[i]];
		int ny = cur.first + dy[ndir];
		int nx = cur.second + dx[ndir];
		if (ny < 0 || nx < 0 || ny > 10 || nx > 10) continue;
		if (!visit[ny][nx][cur.first][cur.second]) {
			visit[ny][nx][cur.first][cur.second] = true;
			visit[cur.first][cur.second][ny][nx] = true;
			answer++;
		}
		cur = { ny, nx };
	}
	return answer;
}