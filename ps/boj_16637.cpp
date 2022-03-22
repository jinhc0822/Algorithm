#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*2022.03.22
프로그래머스에 있는 사칙연산 문제랑 거의 똑같은 문제인줄 알았는데 연산을 무조건 앞에서부터 해야하고
괄호는 중첩이 안돼서 두 항 밖에 묶지 못한다는 제약이 있어 조금은 다른 문제였다...
간단한 문제인데 조금 시간이 걸렸네. 순서대로 연산을 하기 때문에 지금 연산을 바로 하는 것과
다음 연산을 먼저 묶고 지금거랑 계산하는 방법, 이렇게 2가지밖에 없는데 이걸 어떻게 써줄까 조금 고민을 했다.
ac 풀이는 내가 차선책으로 생각한 풀이였는데 이게 오히려 정답이었다. 처음에는 dfs 인수에 bool을 줘서
지금 연산을 괄호로 묶었는지 아닌지 표시를 해줬었는데 너무 복잡해져서 포기했다.*/

int n, answer = INT_MIN;
string s;
vector<int> num;
vector<char> op;

int calc(int a, int b, char c) {
	switch (c) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}
void dfs(int idx, int res) {
	if (idx == num.size()) {
		if (answer < res)
			answer = res;
		return;
	}
	dfs(idx + 1, calc(res, num[idx], op[idx - 1]));
	if (idx != num.size() - 1)
		dfs(idx + 2, calc(res, calc(num[idx], num[idx + 1], op[idx]), op[idx - 1]));
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num.push_back(s[i] - '0');
		else
			op.push_back(s[i]);
	}
	dfs(1, num[0]);
	cout << answer;
}