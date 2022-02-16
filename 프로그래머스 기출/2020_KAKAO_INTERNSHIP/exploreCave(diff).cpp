#include <vector>
#include <queue>
using namespace std;

/*2022.02.15
일단 주어진 길들은 무향 그래프로 만들고 order에 있는 길들은 유향으로 만들어 0에서 dfs를 돌았을 때
방문하지 않은 점이 있으면 실패라고 생각했다. 근데
주어진 길들을 유향 그래프로 하면 안되는 건가보다. 처음에는 나도 이게 트리의 부모->자손 방향의 간선만
있어야하지 않나 생각했는데 생각해보니 무향 간선이라도 상관없을 것 같았는데 60점이 나왔다. 
사실 아직 반례를 잘 모르겠다.
인터넷에서 본 풀이는 0을 루트로 하고 부모->자식 방향으로만 갈 수 있는 단방향 그래프를 만들고
그 그래프에 사이클이 존재하면 불가능하다고 풀이했다. 납득은 가지만 내 건 왜 안되는거지..*/

vector<int> graph[200000];
vector<int> adj[200000];
vector<bool> visit, finish;
bool answer = true;

void dfs(int cur) {
	if (!answer)
		return;
	visit[cur] = 1;
	for (auto next : graph[cur]) {
		if (!visit[next])
			dfs(next);
		else if (!finish[next]) {
			answer = false;
			return;
		}
	}
	finish[cur] = 1;
	return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	for (auto p : path) {
		adj[p[0]].push_back(p[1]);
		adj[p[1]].push_back(p[0]);
	}
	queue<int> q;
	q.push(0);
	visit.assign(n, 0);
	visit[0] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto a : adj[cur]) {
			if (visit[a]) continue;
			visit[a] = true;
			graph[cur].push_back(a);
			q.push(a);
		}
	}
	for (auto o : order) {
		if (o[1] == 0) return false;
		graph[o[0]].push_back(o[1]);
	}
	visit.assign(n, 0);
	finish.assign(n, 0);
	dfs(0);
	return answer;
}

/*
vector<int> indegree; // 먼저 방문해야하는 방의 개수
vector<pair<int, bool>> adj[200000];
vector<bool> visit;

void dfs(int cur) {
	visit[cur] = true;
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i].first;
		bool state = adj[cur][i].second;
		if (state) indegree[next]--;
		if (visit[next] || indegree[next] > 0)
			continue;
		dfs(next);
	}
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	visit.resize(n);
	indegree.resize(n);
	for (int i = 0; i < path.size(); i++) {
		vector<int> v = path[i];
		adj[v[0]].push_back({ v[1], false });
		adj[v[1]].push_back({ v[0], false });
	}
	for (int i = 0; i < order.size(); i++) {
		vector<int> v = order[i];
		adj[v[0]].push_back({ v[1], true });
		indegree[v[1]]++;
	}
	if (indegree[0] > 0)
		return false;
	dfs(0);
	for (int i = 0; i < n; i++)
		if (!visit[i])
			return false;
	return true;
}*/