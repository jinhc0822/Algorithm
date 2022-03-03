#include <string>
#include <vector>
using namespace std;

/*2022.03.03
���߿� ������� �����ϴ� �� �ð��ʰ� �������� �˾Ҵµ� ���ڿ����� 110�� �����ϴ°�
�����̾���. ������ ���ö� �������� ǰ.. �ٵ� �˰��� ����� ���յ� �ð��ʰ���������
��.. �ϴ� ���ڿ����� 110�� ���� ����� ���� ���ڿ����� Ư�� ���ڰ� ���� ��쿡 �ű⿡ �����Ѵٶ��
�߻� ��ü�� �¾Ҵµ� ����� ���� ������ �̿��ϴ� �Ͱ� Ư�� ������ �����ϴ� �ſ��� �ð��� ���� ���.
110�� ����� �� ��ȣ ������ �ſ� ����ؼ� �ű⼭ �ٷ� ������ ���� ��ġë����ϴµ�..*/

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