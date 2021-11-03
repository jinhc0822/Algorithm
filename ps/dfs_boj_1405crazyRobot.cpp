#include <iostream>
#include <cmath>
#define E 1.0e-9
using namespace std;

/*2021.11.03
중간에 풀다가 백트래킹 문제라는 것을 깨달았다. 다행히 어렵지는 않았음.
마지막 출력에서 문제가 생기나 했는데 맞았다고 나와서 다행*/

int n, p[4]; // 순서대로 동서남북
bool visit[30][30];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
double ans;

void dfs(int y, int x, int num, double probability) {
	if (num == n) {
		ans += probability;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (p[i] == 0) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = true;
		dfs(ny, nx, num + 1, probability * (p[i] / 100.0));
		visit[ny][nx] = false;
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> p[i];
	visit[15][15] = true;
	dfs(15, 15, 0, 1.0);
	cout << fixed;
	cout.precision(9);
	cout << ans;
}