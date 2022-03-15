#include <vector>
#include <string>
#define INF 987654321
using namespace std;

/*2022.03.15
트라이로 문자열들을 저장한 후에 반신반의하면서 dfs로 완전탐색 돌렸는데 역시 시간초과..
dfs 안에서 find하는 걸 dfs 밖에서 미리 계산하고 돌려도 시간초과.. 다른 방법이 필요한 듯하다.*/

struct Trie {
	Trie* node[26];
	bool finish;
	Trie() {
		finish = false;
		for (int i = 0; i < 26; i++)
			node[i] = NULL;
	}
	void insert(string s, int idx) {
		if (idx == s.size()) {
			finish = true;
			return;
		}
		int cur = s[idx] - 'a';
		if (node[cur] == NULL)
			node[cur] = new Trie();
		node[cur]->insert(s, idx + 1);
	}
	bool find(string s, int idx) {
		if (idx == s.size()) {
			if (finish) return true;
			return false;
		}
		int cur = s[idx] - 'a';
		if (node[cur] == NULL) return false;
		return node[cur]->find(s, idx + 1);
	}
};
int answer = INF;
vector<int> exist[20000];
Trie* root;

void dfs(int cnt, int idx, string t) {
	if (idx == t.size()) {
		if (answer > cnt)
			answer = cnt;
	}
	for (int i : exist[idx])
		dfs(cnt + 1, idx + i, t);
}
int solution(vector<string> strs, string t) {
	root = new Trie();
	for (string s : strs)
		root->insert(s, 0);
	for (int i = 0; i < t.size(); i++) {
		for (int j = 1; j <= 5; j++) {
			if (i + j > t.size())
				break;
			string s = t.substr(i, j);
			if (root->find(s, 0))
				exist[i].push_back(j);
		}
	}
	dfs(0, 0, t);
	return (answer == INF) ? -1 : answer;
}