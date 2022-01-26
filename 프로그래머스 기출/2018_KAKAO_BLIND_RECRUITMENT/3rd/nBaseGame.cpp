#include <string>
#include <vector>
using namespace std;

/*2022.01.25
초반에 어떻게 짜야할지 좀 고민을 했긴 한데 dfs로 게임의 전체 순번을 다 구했다.
근데 카카오 문제 해설을 보니 그냥 진법 변환으로 풀어도 무방했던 것 같다. 나도 그 생각을 안 한 것은 아니지만 
어차피 숫자는 1씩 올라가서 엄청 간단한데 각자 다 진법변환 쓰기는 뭔가 손해보는 기분이 들었다.*/

string s = "";
char num[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void dfs(string str, int n, int digit, int idx) {
	if (idx == digit) {
		s += str;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (idx == 0 && i == 0)
			continue;
		dfs(str + num[i], n, digit, idx + 1);
	}
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	for (int i = 0; i < n; i++)
		s += num[i];
	// i의 제한이 16인 이유는 10만이 전체 게임에 말해야하는 숫자 수의 제한인데 가장 자릿수가 올라갈 확률이 큰 2진수일 때 그 제한이 2의 14-15승 정도라서.
	for (int i = 2; i < 16; i++) {
		if (s.size() >= t * m)
			break;
		dfs("", n, i, 0);
	}
	if (m == p)
		p = 0;
	for (int i = 0; answer.size() < t; i++) {
		if ((i + 1) % m == p)
			answer.push_back(s[i]);
	}
	return answer;
}