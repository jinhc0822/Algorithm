#include <vector>
using namespace std;

/*2022.02.24
dfs로 풀려고 했지만 실패. 결국 답을 봄.
dp[i][j]=k : i의 시간에 j에 있을 때 고쳐야하는 로그의 최소 횟수
라는 힌트를 보고 풀어보자..*/

int answer;
bool adj[201][201];
vector<int> adjList[201];

void dfs(int cur, int t, int fixErr, vector<int>& log) { // t는 0부터 시작
	if (t == log.size() - 1) {
		if (cur == log.back() && fixErr < answer)
			answer = fixErr;
		return;
	}
	if (adj[cur][log[t + 1]])
		dfs(log[t + 1], t + 1, fixErr, log);
	else {
		for (int i = 0; i < adjList[cur].size(); i++) {
			int next = adjList[cur][i];
			dfs(next, t + 1, fixErr + 1, log);
		}
	}
}
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	answer = 987654321;
	for (int i = 0; i < m; i++) {
		adj[edge_list[i][0]][edge_list[i][1]] = true;
		adj[edge_list[i][1]][edge_list[i][0]] = true;
		adjList[edge_list[i][0]].push_back(edge_list[i][1]);
		adjList[edge_list[i][1]].push_back(edge_list[i][0]);
	}
	dfs(gps_log[0], 0, 0, gps_log);
	return answer;
}