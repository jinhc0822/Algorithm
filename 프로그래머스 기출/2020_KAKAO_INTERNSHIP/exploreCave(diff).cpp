#include <vector>
#include <queue>
using namespace std;

/*2022.02.15
�ϴ� �־��� ����� ���� �׷����� ����� order�� �ִ� ����� �������� ����� 0���� dfs�� ������ ��
�湮���� ���� ���� ������ ���ж�� �����ߴ�. �ٵ�
�־��� ����� ���� �׷����� �ϸ� �ȵǴ� �ǰ�����. ó������ ���� �̰� Ʈ���� �θ�->�ڼ� ������ ������
�־������ �ʳ� �����ߴµ� �����غ��� ���� �����̶� ������� �� ���Ҵµ� 60���� ���Դ�. 
��� ���� �ݷʸ� �� �𸣰ڴ�.
���ͳݿ��� �� Ǯ�̴� 0�� ��Ʈ�� �ϰ� �θ�->�ڽ� �������θ� �� �� �ִ� �ܹ��� �׷����� �����
�� �׷����� ����Ŭ�� �����ϸ� �Ұ����ϴٰ� Ǯ���ߴ�. ������ ������ �� �� �� �ȵǴ°���..*/

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
vector<int> indegree; // ���� �湮�ؾ��ϴ� ���� ����
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