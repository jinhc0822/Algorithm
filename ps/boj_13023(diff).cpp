#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*2022.04.07
와.. 이거 쉬운줄 알고 금방 풀었는데 이상하게 틀린 부분이 없는데 왜 계속 틀리지 싶었는데
dfs 안에 visit[cur]=false가 꼭 필요한 문제였다. 무턱대고 방문할 때마다 true를 하게 되면
나중에 다른 노드를 거쳐서 갈 때 문제가 된다.
5 5
0 1
1 2
2 3
1 3
3 4
위의 예제에서 visit[cur]=false가 없다면 1에서 3에 갔을 때 visit[3]이 true가 되고 
나중에 012를 거쳐 3으로 갈 때 이미 3이 방문한 걸로 체크가 되어 답을 찾지 못하게 된다...
너무 안일하게 생각했나?.. ㅜ*/

int n, m;
bool visit[2000], chk;
vector<vector<int>> adj;

void dfs(int cur, int depth) {
	if (depth == 4) {
		chk = true;
		return;
	}
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (!visit[next])
			dfs(next, depth + 1);
		if (chk) return;
	}
	visit[cur] = false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i, 0);
		if (chk) break;
	}
	if (chk) cout << 1;
	else cout << 0;
}