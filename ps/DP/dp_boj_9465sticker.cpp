#include <iostream>
#include <algorithm>
using namespace std;

/*2021.11.29
전에 풀었던 문제. 전에는 반복적 dp로 풀었으므로 이번에는 재귀적으로 품.
cur를 0부터 해서 하는 방법도 있겠지만 for문 돌리기 싫어서 -1로 시작했는데
하면서 약간 헷갈렸다.*/

int n, tc, sc[2][100000];
int cache[100000][3]; //고르지 않으면 0, 위에것을 고를 시 1, 밑의 것을 고를 시 2 

int score(int cur, int pick) {
	if (cur == n - 2) {
		if (pick == 0) return max(sc[0][cur + 1], sc[1][cur + 1]);
		else if (pick == 1) return sc[1][cur + 1];
		else return sc[0][cur + 1];
	}
	int& ret = cache[cur + 1][pick];
	if (ret != -1) return ret;
	if (pick == 0) ret = max({ score(cur + 1, 0), score(cur + 1, 1) + sc[0][cur + 1],
		score(cur + 1, 2) + sc[1][cur + 1] });
	else if (pick == 1) ret = max(score(cur + 1, 0), score(cur + 1, 2) + sc[1][cur + 1]);
	else ret = max(score(cur + 1, 0), score(cur + 1, 1) + sc[0][cur + 1]);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> sc[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cache[i][j] = -1;
		cout << score(-1, 0) << '\n';
	}
}