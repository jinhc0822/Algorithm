#include <string>
#include <vector>
#include <stack>
using namespace std;

/*2022.03.01
그냥 완전탐색 돌리면 됨.*/

bool correctString(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			if (st.empty()) return false;
			if (st.top() != '(') return false;
			st.pop();
		}
		else if (s[i] == '}') {
			if (st.empty()) return false;
			if (st.top() != '{') return false;
			st.pop();
		}
		else if (s[i] == ']') {
			if (st.empty()) return false;
			if (st.top() != '[') return false;
			st.pop();
		}
		else
			st.push(s[i]);
	}
	if (!st.empty())
		return false;
	return true;
}
int solution(string s) {
	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		if (correctString(s))
			answer++;
		s = s.substr(1) + s[0];
	}
	return answer;
}