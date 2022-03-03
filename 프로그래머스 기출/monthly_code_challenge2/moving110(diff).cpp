#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.03
나중에 결과물을 조합하는 게 시간초과 원인인줄 알았는데 문자열에서 110을 제거하는게
원인이었다.*/

vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;
		while (true) {
			if (s[i].find("110") != string::npos) {
				int idx = s[i].find("110");
				cnt++;
				s[i] = s[i].substr(0, idx) + s[i].substr(idx + 3);
			}
			else break;
		}
		vector<string> tmp;
		string k = "";
		for (int i = 0; i < cnt; i++)
			k += "110";
		for (int j = 0; j <= s[i].size(); j++) {
			string a = s[i].substr(0, j) + k;
			if (j < s[i].size()) a += s[i].substr(j);
			tmp.push_back(a);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(tmp[0]);
		/*if (s[i].find("11") != string::npos) {
			int idx = s[i].find("11");
			res = s[i].substr(0, idx) + k + s[i].substr(idx);
		}
		else {
			if (s[i].rfind("0") != string::npos) {
				int idx = s[i].rfind("0");
				res = s[i].substr(0, idx + 1) + k;
				if (idx + 1 != s[i].size())
					res += s[i].substr(idx + 1);
			}
			else
				res = k + s[i];
		}
		answer.push_back(res);*/
	}
	return answer;
}