#include <string>
#include <vector>
using namespace std;

/*2022.03.03
나중에 결과물을 조합하는 게 시간초과 원인인줄 알았는데 문자열에서 110을 제거하는게
원인이었다. 스택이 떠올라서 스택으로 품.. 근데 알고보니 결과물 조합도 시간초과였음ㅋㅋ
휴.. 일단 문자열에서 110을 전부 지우고 남은 문자열에서 특정 문자가 있을 경우에 거기에 삽입한다라는
발상 자체는 맞았는데 지우는 데에 스택을 이용하는 것과 특정 조건을 생각하는 거에서 시간을 많이 썼다.
110을 지우는 게 괄호 지우기랑 매우 비슷해서 거기서 바로 스택인 것을 눈치챘어야하는데..*/

vector<string> solution(vector<string> s) {
	vector<string> answer;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0, top2 = -2, top = -1;
		vector<char> stack(1000000);
		for (int j = 0; j < s[i].size(); j++) {
			if (top2 < 0 || top < 0) {
				stack[++top] = s[i][j];
				top2++;
			}
			else if (stack[top2] == '1' && stack[top] == '1' && s[i][j] == '0') {
				top2 -= 2;
				top -= 2;
				cnt++;
			}
			else {
				stack[++top] = s[i][j];
				top2++;
			}
		}
		s[i].clear();
		for (int j = 0; j <= top; j++)
			s[i] += stack[j];
		string k = "", res;
		for (int j = 0; j < cnt; j++)
			k += "110";
		if (s[i].find("11") != string::npos) {
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
		answer.push_back(res);
	}
	return answer;
}