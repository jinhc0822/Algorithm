#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*2022.03.26
어차피 전체 구역 개수가 최대 10개이니 완전 탐색으로 될 것이라고 생각했다. 10개에서 (1, 9), (2, 8), ... (5, 5)로
묶는 경우의 수를 전부 계산해도 1000보다 작은 숫자라 될 것이라고 생각했다. 그래서 선택한 조합에서 각각 dfs를 두번씩
돌려서 모두 한 묶음으로 묶여 있는지를 계산하면 될 것이라고 생각했다. 근데 dfs 구현하는 데에서 시간을 너무 
써버렸네 ㅜㅜ..*/

int n, population[10], answer = 987654321;
bool visit[10];
vector<int> adj[10];
vector<bool> b;

void dfs(int cur, int cnt, int k, int g) {
	if (cnt >= k)
		return;
	visit[cur] = true;
	for (int next : adj[cur])
		if (((1 << next) & g) && !visit[next])
			dfs(next, cnt + 1, k, g);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> population[i];
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			adj[i].push_back(b - 1);
		}
	}
	for (int i = 1; i <= n / 2; i++) {
		b.assign(n, true);
		for (int j = 0; j < n - i; j++)
			b[j] = false;
		do {
			int A = 0, B = 0;
			for (int j = 0; j < n; j++) {
				if (b[j]) A |= (1 << j);
				else B |= (1 << j);
			}
			memset(visit, false, sizeof(visit));
			for (int j = 0; j < n; j++) {
				if (b[j]) {
					dfs(j, 0, i, A);
					break;
				}
			}
			bool chk = true;
			for (int j = 0; j < n; j++) {
				if (b[j] && !visit[j]) {
					chk = false;
					break;
				}
			}
			if (!chk) continue; 
			memset(visit, false, sizeof(visit));
			for (int j = 0; j < n; j++) {
				if (!b[j]) {
					dfs(j, 0, n - i, B);
					break;
				}
			}
			chk = true;
			for (int j = 0; j < n; j++) {
				if (!b[j] && !visit[j]) {
					chk = false;
					break;
				}
			}
			if (!chk) continue;
			int sumA = 0, sumB = 0;
			for (int j = 0; j < n; j++) {
				if (b[j])
					sumA += population[j];
				else
					sumB += population[j];
			}
			int k = (sumA > sumB) ? sumA - sumB : sumB - sumA;
			answer = min(answer, k);
		} while (next_permutation(b.begin(), b.end()));
	}
	if (answer == 987654321)
		cout << -1;
	else
		cout << answer;
}