#include <vector>
#include <string>
using namespace std;

/*2022.01.13
선형적인 방식으로는 효율성 테스트를 절대 통과할 수가 없다고 한다..
트라이 같은 알고리즘을 사용할 경우에만 통과할 수 있다고 한다... 조금 아쉽네..*/

int ans[100000];
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
}