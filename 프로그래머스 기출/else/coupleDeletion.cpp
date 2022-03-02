#include <string>
#include <stack>
using namespace std;

/*2022.03.02
처음에는 그냥 문제 그대로 문자열로 하려다가 시간초과. 한번 시간초과 나니까 스택이 떠오름..*/

int solution(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (st.empty())
			st.push(s[i]);
		else if (st.top() != s[i])
			st.push(s[i]);
		else if (st.top() == s[i])
			st.pop();
	}
	if (st.empty()) return 1;
	else return 0;
}