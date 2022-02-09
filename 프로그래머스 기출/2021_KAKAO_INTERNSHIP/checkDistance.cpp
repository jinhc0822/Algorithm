#include <string>
#include <vector>
#include <queue>
#define SIZE 5
using namespace std;

/*2022.02.09
정석 풀이 같긴 하다. 할만함.*/

struct Info {
	int r;
	int c;
	bool chk;
};
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool bfs(int y, int x, vector<string>& place) {
	queue<Info> q;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= SIZE || nx >= SIZE) continue;
		if (place[ny][nx] == 'P')
			return false;
		bool k = (place[ny][nx] == 'X') ? true : false;
		q.push({ ny, nx, k });
	}
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.r + dy[i];
			int nx = cur.c + dx[i];
			if (ny < 0 || nx < 0 || ny >= SIZE || nx >= SIZE) continue;
			if (ny == y && nx == x) continue;
			if (place[ny][nx] == 'P' && cur.chk == false)
				return false;
		}
	}
	return true;
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < SIZE; i++) {
		bool chk = true;
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				if (places[i][j][k] == 'P')
					chk = bfs(j, k, places[i]);
				if (!chk)
					break;
			}
			if (!chk)
				break;
		}
		if (chk)
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	return answer;
}