#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*2022.03.31
후위 표기식은 처음이었는데 이런 식으로 바꾸는 것은 처음 본 것 같다. 내가 기억을 못하는건가?..
괄호가 아닌 사칙연산일 경우에 while문 안의 조건이 어떻게 나온건지 이해가 잘 되지 않네..
->  스택 안에서 현재 연산자의 우선순위보다 top의 우선순위가 같거나 높은 경우 출력해준다.
	우선순위는 (*, /) (+, -) ( ( ) 순으로 높다.
push를 나중에 하는 것도 특이하다.*/

string s;
stack<char> op;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			cout << s[i];
		else {
			if (s[i] == '(')
				op.push(s[i]);
			else if (s[i] == '*' || s[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.push(s[i]);
			}
			else if (s[i] == ')') {
				while (!op.empty() && op.top() != '(') {
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
}