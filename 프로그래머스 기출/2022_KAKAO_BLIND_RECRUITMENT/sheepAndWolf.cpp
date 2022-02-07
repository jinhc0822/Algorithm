#include <string>
#include <vector>
using namespace std;

/*2022.02.07
�и� ����� ���� �����ε� ������ �湮�ؾ��� ��� �����ϴ� �� ������ �ȳ��� �� ���� �ɸ�.
string ���� �� ���� �ٸ� ����� ���� �� ����. ���� �ؼ����� ��Ʈ����ŷ�� �̿��߳�.*/

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