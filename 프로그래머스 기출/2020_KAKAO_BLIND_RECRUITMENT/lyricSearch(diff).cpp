#include <vector>
#include <string>
#include <map>
using namespace std;

/*2022.01.13
선형적인 방식으로는 효율성 테스트를 절대 통과할 수가 없다고 한다..
트라이 같은 알고리즘을 사용할 경우에만 통과할 수 있다고 한다... 조금 아쉽네..
밑의 코드는 얍문 님의 코드를 그대로 따온 것*/

struct TRIE {
	TRIE* node[26];
	int childCnt;
	bool finish;
	void insert(const char* str);
	int find(const char* str);
};
int idx = 0;
TRIE* trie[10001], * rTrie[10001];
TRIE nodepool[2000010]; // 갯수 제한이 있으니 동적할당을 쓰지 않고 주소를 할당하기 위해 사용한 것 같다.

TRIE* nodeset() {
	TRIE* newNode = &nodepool[idx++];
	newNode->childCnt = 0;
	newNode->finish = false;
	for (int i = 0; i < 26; i++)
		newNode->node[i] = NULL;
	return newNode;
}
void TRIE::insert(const char* str) {
	childCnt++;
	if (*str == NULL) {
		finish = true;
		return;
	}
	int cur = *str - 'a';
	if (node[cur] == NULL) node[cur] = nodeset();
	node[cur]->insert(str + 1);
}
int TRIE::find(const char* str) {
	if (*str == '?') return childCnt;
	int cur = *str - 'a';
	if (node[cur] == NULL) return 0;
	return node[cur]->find(str + 1);
}
int chkState(string s) {
	if (s[0] == '?') return 0;
	else return 1;
}
string reverse(string s) {
	string tmp = "";
	for (int i = s.size() - 1; i >= 0; i--)
		tmp += s[i];
	return tmp;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	for (string s : words) {
		int len = s.length();
		if (trie[len] == NULL)
			trie[len] = nodeset();
		trie[len]->insert(s.c_str());

		string reverseS = reverse(s);
		if (rTrie[len] == NULL)
			rTrie[len] = nodeset();
		rTrie[len]->insert(reverseS.c_str());
	}
	map<string, int> m;
	for (int i = 0; i < queries.size(); i++) {
		string s = queries[i];
		if (m.count(s) == 0) {
			m[s] = i;
			int len = s.length();
			int state = chkState(s);
			if (state == 1) {
				if (trie[len] == NULL)
					answer.push_back(0);
				else
					answer.push_back(trie[len]->find(s.c_str()));
			}
			else {
				string reverseS = reverse(s);
				if (rTrie[len] == NULL)
					answer.push_back(0);
				else
					answer.push_back(rTrie[len]->find(reverseS.c_str()));
			}
		}
		else answer.push_back(answer[m[s]]);
	}
	return answer;
}

/*int ans[100000];
vector<string> w[10001];
vector<pair<int, pair<string, int>>> preQ, suQ;

vector<int> solution(vector<string> words, vector<string> queries){
	vector<int> answer;
	for (string s : words)
		w[s.size()].push_back(s);
	for (int i = 0; i < queries.size(); i++) {
		if (queries[i][0] == '?')
			preQ.push_back({ queries[i].size(), { queries[i], i } });
		else
			suQ.push_back({ queries[i].size(), { queries[i], i } });
	}
	for (int i = 0; i < suQ.size(); i++) {
		int sz = suQ[i].first;
		string q = suQ[i].second.first;
		int idx = q.find('?');
		string sub = q.substr(0, idx);
		for (string s : w[sz])
			if (sub == s.substr(0, idx))
				ans[suQ[i].second.second]++;
	}
	for (int i = 0; i < preQ.size(); i++) {
		int sz = preQ[i].first;
		string q = preQ[i].second.first;
		int idx = q.rfind('?');
		string sub = q.substr(idx + 1);
		for (string s : w[sz])
			if (sub == s.substr(idx + 1))
				ans[preQ[i].second.second]++;
	}
	for (int i = 0; i < queries.size(); i++)
		answer.push_back(ans[i]);
	return answer;
}*/