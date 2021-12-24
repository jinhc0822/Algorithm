#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
#define INF 1000000000000000
using namespace std;

/*2021.12.22
후... 예외 찾기는 너무 힘들어.. 일단 최댓값을 구해야하기에 도시에서 벌 수 있는 돈을 음수로 했다.
그리고 출발지에서 도착지로 갈 수 없는 경우를 dfs를 사용해서 해결했고 그 후 벨만 포드를 사용했는데 
음의 사이클이 존재한다고 해서 무조건 돈을 무한대로 불릴 수 있는 것이 아니라 그 사이클에서
도착지에 갈 수 있는지도 체크를 해줘야하기 때문에 벨만포드 코드 안에 dfs를 넣었다. 그리고 
n이 100이고 그 도시들이 전부 사이클을 이룰 시에 int형의 최댓값을 넘을 수도 있기 때문에 upper 값을
long long으로 해줘야만 한다. 100개의 도시가 사이클을 이룰 경우를 생각을 못했다...*/

int n, s, e, m, money[MAX], earn;
bool visit[MAX];
vector<pair<int, int>> road[MAX];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < road[x].size(); i++) {
		int next = road[x][i].first;
		if (visit[next]) continue;
		dfs(next);
	}
}
vector<long long> bellmanFord(int src) {
	vector<long long> upper(n, INF);
	upper[src] = money[src];
	bool updated;
	for (int i = 0; i < n; i++) {
		updated = false;
		for (int here = 0; here < n; here++) {
			if (upper[here] == INF) continue;
			for (int j = 0; j < road[here].size(); j++) {
				int there = road[here][j].first;
				int cost = road[here][j].second;
				if (upper[there] > upper[here] + cost + money[there]) {
					upper[there] = upper[here] + cost + money[there];
					updated = true;
					if (i == n - 1) {
						memset(visit, false, sizeof(visit));
						dfs(here);
						if (visit[e]) {
							upper.clear();
							return upper;
						}
					}
				}
			}
		}
		if (!updated) break;
	}
	return upper;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back(make_pair(b, c));
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		money[i] = -a;
	}
	dfs(s);
	if (!visit[e]) {
		cout << "gg";
		return 0;
	}
	vector<long long> res = bellmanFord(s);
	if (res.empty()) cout << "Gee";
	else cout << -res[e];
}