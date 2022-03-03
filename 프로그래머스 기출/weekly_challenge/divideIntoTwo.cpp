#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

/*2022.03.02
완전탐색 사용함*/

bool visit[101], adj[101][101];
vector<int> adjList[101];

int dfs(int cur) {
	int res = 0;
	visit[cur] = true;
	for (int i = 0; i < adjList[cur].size(); i++) {
		int next = adjList[cur][i];
		if (visit[next] || !adj[cur][next])
			continue;
		res += dfs(next);
	}
	return res + 1;
}
int solution(int n, vector<vector<int>> wires) {
	int answer = 98754321;
	for (int i = 0; i < wires.size(); i++) {
		adjList[wires[i][0]].push_back(wires[i][1]);
		adjList[wires[i][1]].push_back(wires[i][0]);
		adj[wires[i][0]][wires[i][1]] = true;
		adj[wires[i][1]][wires[i][0]] = true;
	}
	for (int i = 0; i < wires.size(); i++) {
		adj[wires[i][0]][wires[i][1]] = false;
		adj[wires[i][1]][wires[i][0]] = false;
		memset(visit, false, sizeof(visit));
		int diff = abs(dfs(wires[i][0]) - dfs(wires[i][1]));
		if (diff < answer)
			answer = diff;
		adj[wires[i][0]][wires[i][1]] = true;
		adj[wires[i][1]][wires[i][0]] = true;
	}
	return answer;
}