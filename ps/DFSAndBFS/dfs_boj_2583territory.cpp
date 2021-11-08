#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*2021.11.01
30분 정도 걸림. 문제에서 주어지는 것은 점에 대한 좌표인데
배열에서는 칸의 좌표로 나타낼 수 밖에 없어서 헷갈리기 딱 좋음
게다가 맨 밑의 행이 0이라서 배열과 반대라는 점에서도 헷갈리기 좋음.
어차피 원본이랑 대칭이라서 생각만 조금 해준다면 빈 칸의 개수는
같기 때문에 답은 같음. 정답 비율이 절반을 넘어서 이것도 10분만에
풀리겠거니 했는데 헷갈릴만한 요소가 좀 있었다.*/

int m, n, k, ans, cnt;
bool paper[101][101];
bool visit[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<int> v;

void dfs(int y, int x) {
	cnt++;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <= 0 || nx < 0 || ny > m || nx >= n) continue;
		if (paper[ny][nx] || visit[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1 + 1; y <= y2; y++)
			for (int x = x1; x <= x2 - 1; x++)
				paper[y][x] = true;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] || visit[i][j]) continue;
			dfs(i, j);
			v.push_back(cnt);
			cnt = 0;
			ans++;
		}
	}
	sort(v.begin(), v.end());
	cout << ans << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}