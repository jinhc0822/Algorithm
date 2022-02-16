#include <string>
#include <vector>
#include <map>
using namespace std;

/*2022.02.16*/

bool isNum(char c) {
	return c >= '0' && c <= '9';
}
vector<int> solution(string s) {
	vector<int> answer, v;
	vector<int> e[501];
	map<int, bool> fin;
	int tupleSize = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (isNum(s[i])) {
			int k = 1;
			while (isNum(s[i + k]))
				k++;
			v.push_back(stoi(s.substr(i, k)));
			i += (k - 1);
		}
		else if (s[i] == '}') {
			int sz = v.size();
			tupleSize = (sz > tupleSize) ? sz : tupleSize;
			for (int j = 0; j < sz; j++)
				e[sz].push_back(v[j]);
			v.clear();
		}
	}
	for (int i = 1; i <= tupleSize; i++) {
		for (int k : e[i]) {
			if (!fin[k]) {
				answer.push_back(k);
				fin[k] = true;
			}
		}
	}
	return answer;
}