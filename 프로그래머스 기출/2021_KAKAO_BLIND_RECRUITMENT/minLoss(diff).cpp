#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;

/*2022.01.17
분류가 없어서 그런지.. 어떻게 시작해야할지 감을 잡지 못해 인터넷에서 답을 봤다. 
흔히 나오는 알고리즘 종류를 떠올리면서 하나하나 이걸로 풀 수 있겠는지 생각하는 것이 중요한 것 같다.*/

int dp[MAX][2];
vector<int> node[MAX];
vector<int> cost;

void dfs(int cur) {
	bool leafNode = true;
	for (int i = 0; i < node[cur].size(); i++) {
		int next = node[cur][i];
		leafNode = false;
		dfs(next);
	}
	if (leafNode) {
		dp[cur][0] = 0;
		dp[cur][1] = cost[cur - 1];
		return;
	}
	int sum = 0;
	int minCost = 987654321;
	bool attend = true;
	for (int i = 0; i < node[cur].size(); i++) {
		int child = node[cur][i];
		sum += min(dp[child][0], dp[child][1]);
		if (dp[child][0] >= dp[child][1]) attend = false;
		minCost = min(minCost, dp[child][1] - dp[child][0]);
	}
	dp[cur][1] = cost[cur - 1] + sum;
	if (!attend) dp[cur][0] = sum;
	else dp[cur][0] = sum + minCost;
}
int solution(vector<int> sales, vector<vector<int>> links) {
	int answer = 0;
	cost = sales;
	for (int i = 0; i < links.size(); i++)
		node[links[i][0]].push_back(links[i][1]);
	dfs(1);
	answer = min(dp[1][0], dp[1][1]);
	return answer;
}