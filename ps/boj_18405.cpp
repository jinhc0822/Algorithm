#include <iostream>
#include <queue>
using namespace std;

/*2022.05.09
쉬움.*/

struct Info {
	int y;
	int x;
	int t;
};
int n, k, tube[200][200];
int ansX, ansY, s;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
queue<Info> virus[1001];

void proliferation(int time) {
	for (int i = 1; i <= k; i++) {
		while (!virus[i].empty()) {
			Info v = virus[i].front();
			if (v.t != time) break;
			virus[i].pop();
			for (int j = 0; j < 4; j++) {
				int ny = v.y + dy[j];
				int nx = v.x + dx[j];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (tube[ny][nx] != 0) continue;
				tube[ny][nx] = i;
				virus[i].push({ ny, nx, v.t + 1 });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tube[i][j];
			if (tube[i][j] != 0)
				virus[tube[i][j]].push({ i, j, 0 });
		}
	}
	cin >> s >> ansX >> ansY;
	for (int i = 0; i < s; i++)
		proliferation(i);
	cout << tube[ansX - 1][ansY - 1];
}