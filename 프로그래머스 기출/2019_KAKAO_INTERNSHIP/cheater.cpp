#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.02.17
자잘한 실수 때문에 조금 오래 걸렸네.. 
처음에는 트라이를 써야하나 생각했는데 user_id 최대 개수가 8개밖에 안돼서
완전탐색을 사용했다.*/

vector<int> ans;
vector<int> v[8];

bool comp(string s, string s2) {
	if (s.size() != s2.size())
		return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') continue;
		else if (s[i] != s2[i])
			return false;
	}
	return true;
}
void dfs(int idx, int cur, int sz) {
	if (idx == sz) {
		ans.push_back(cur);
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		int k = v[idx][i];
		if (cur & (1 << k))
			continue;
		dfs(idx + 1, cur | (1 << k), sz);
	}
}
int solution(vector<string> user_id, vector<string> banned_id) {
	for (int i = 0; i < banned_id.size(); i++)
		for (int j = 0; j < user_id.size(); j++)
			if (comp(banned_id[i], user_id[j]))
				v[i].push_back(j);
	dfs(0, 0, banned_id.size());
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	return ans.size();
}