#include <string>
#include <vector>
using namespace std;

/*2022.02.03
트라이를 알고 있다면 쉬운 문제. 근데 다른 풀이도 있더라.
단어들을 사전 순으로 정렬해서 좌우 단어가 자신과 가장 비슷한 단어이므로
좌우 단어들과 비교해서 겹치는 수가 가장 큰 것을 반환*/

struct TRIE {
	int curLen, num = 0;
	bool finish;
	TRIE* node[26];
	TRIE() {
		finish = false;
		for (int i = 0; i < 26; i++)
			node[i] = NULL;
	}
	void insert(const char* str, int len) {
		curLen = len;
		num++;
		if (*str == NULL) {
			finish = true;
			return;
		}
		int cur = *str - 'a';
		if (node[cur] == NULL)
			node[cur] = new TRIE();
		node[cur]->insert(str + 1, len + 1);
	}
	int find() {
		int res = 0;
		for (int cur = 0; cur < 26; cur++) {
			if (node[cur] == NULL)
				continue;
			else if (node[cur]->num == 1) {
				res += node[cur]->curLen;
				continue;
			}
			else if (node[cur]->finish)
				res += node[cur]->curLen;
			res += node[cur]->find();
		}
		return res;
	}
};

int solution(vector<string> words) {
	int answer = 0;
	TRIE* root = new TRIE();
	for (int i = 0; i < words.size(); i++)
		root->insert(words[i].c_str(), 0);
	answer = root->find();
	return answer;
}