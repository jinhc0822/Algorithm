#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

/*일단 처음으로 다시 돌아와서 생각을 해봤는데 그냥 완점탐색으로 풀어도 될 것 같았다.
정확히 말하자면 백트래킹이긴 한데 dfs함수 초반부에 return할 경우를 넣는게 아니다보니까
dfs함수의 for문 내에서 순서에 관해 조금 헤매서 시간이 많이 걸렸다..
다행히 알고리즘 분류에도 완전탐색과 백트래킹이 있는 걸 보면 맞게 푼 것 같다.*/

vector<pair<int, int>> v;
bool paper[MAX][MAX], visit[MAX][MAX];
int sz[MAX][MAX], paperCnt[6], answer = 987654321;

int calc(int y, int x, bool chk) {
	int cnt = 2;
	for (cnt = 2; cnt <= 5; cnt++) {
		if (x + cnt - 1 >= MAX || y + cnt - 1 >= MAX)
			return cnt - 1;
		for (int i = 0; i < cnt; i++) {
			if (!paper[y + cnt - 1][x + i])
				return cnt - 1;
			if (!paper[y + i][x + cnt - 1])
				return cnt - 1;
		}
	}
	return 5;
}
bool isEmpty() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (!visit[i][j])
				return true;
	return false;
}
bool overlap(int idx, int len) {
	int y = v[idx].first;
	int x = v[idx].second;
	for (int i = y; i < y + len; i++)
		for (int j = x; j < x + len; j++)
			if (visit[i][j])
				return true;
	return false;
}
void dfs(int idx, int cnt) {
	int y = v[idx].first;
	int x = v[idx].second;
	for (int len = 1; len <= sz[y][x]; len++) {
		if (paperCnt[len] == 0)
			continue;
		if (overlap(idx, len))
			continue;
		for (int i = y; i < y + len; i++)
			for (int j = x; j < x + len; j++)
				visit[i][j] = true;
		paperCnt[len]--;
		bool chk = false;
		for (int next = idx + 1; next < v.size(); next++) {
			if (visit[v[next].first][v[next].second]) continue;
			dfs(next, cnt + 1);
			chk = true;
			break;
		}
		for (int i = y; i < y + len; i++)
			for (int j = x; j < x + len; j++)
				visit[i][j] = false;
		paperCnt[len]++;
		if (!chk) {
			if (answer > cnt + 1)
				answer = cnt + 1;
			return;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> paper[i][j];
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visit[i][j] = true;
			if (paper[i][j]) {
				v.push_back({ i, j });
				visit[i][j] = false;
				sz[i][j] = calc(i, j, true);
			}
		}
	}
	for (int i = 1; i <= 5; i++)
		paperCnt[i] = 5;
	if (v.empty()) {
		cout << 0;
		return 0;
	}
	dfs(0, 0);
	if (answer > 100)
		cout << -1;
	else
		cout << answer;
}