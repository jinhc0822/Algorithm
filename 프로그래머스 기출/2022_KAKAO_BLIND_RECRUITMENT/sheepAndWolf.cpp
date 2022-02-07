#include <string>
#include <vector>
using namespace std;

/*2022.02.07
분명 어렵진 않은 문제인데 다음에 방문해야할 노드 전달하는 게 생각이 안나서 좀 오래 걸림.
string 쓰는 거 말고 다른 방법도 있을 것 같다. 공개 해설에는 비트마스킹을 이용했네.*/

int maxSheep;
string str;
vector<int> adj[17];

void dfs(int idx, int wolf, int sheep, string s, vector<int>& v) {
	if (wolf == sheep || s == str) {
		if (maxSheep < sheep)
			maxSheep = sheep;
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') continue;
		s[i] = '0';
		for (int j = 0; j < adj[i].size(); j++)
			s[adj[i][j]] = '1';

		if (v[i] == 0)
			dfs(i, wolf, sheep + 1, s, v);
		else
			dfs(i, wolf + 1, sheep, s, v);

		for (int j = 0; j < adj[i].size(); j++)
			s[adj[i][j]] = '0';
		s[i] = '1';
	}
}
int solution(vector<int> info, vector<vector<int>> edges) {
	string s = "";
	for (int i = 0; i < edges.size(); i++)
		adj[edges[i][0]].push_back(edges[i][1]);
	for (int i = 0; i < info.size(); i++)
		s += '0';
	str = s;
	for (int i = 0; i < adj[0].size(); i++)
		s[adj[0][i]] = '1';
	dfs(0, 0, 1, s, info);
	return maxSheep;
}