#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

/*2022.02.11
구현하는데 좀 애를 먹어서 시간을 좀 썼다..
근데 vs로는 풀리는데 왜 프로그래머스 채점에는 signal aborted가 뜰까??...
진짜 한참을 찾았네... 몇 몇 줄에서 string과 char을 비교하기 위해
char에 일부러 ""을 더해서 비교한 것이 문제였다. 근데 이게 왜 문제가 될까?..*/

long long solution(string expression) {
	long long answer = 0;
	char op[3] = { '*', '+', '-' };
	vector<string> exp;
	int k = 0;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] < '0' || expression[i] > '9') {
			exp.push_back(expression.substr(k, i - k));
			k = i + 1;
			exp.push_back(expression.substr(i, 1));
		}
	}
	exp.push_back(expression.substr(k));
	do {
		queue<string> q;
		vector<string> v;
		for (int i = 0; i < exp.size(); i++)
			q.push(exp[i]);
		while (!q.empty()) {
			if (q.front()[0] == op[0]) {
				long long n = stoll(v.back());
				v.pop_back();
				q.pop();
				long long m = stoll(q.front());
				long long j = (op[0] == '*') ? n * m : (op[0] == '+') ? n + m : n - m;
				v.push_back(to_string(j));
			}
			else
				v.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < v.size(); i++)
			q.push(v[i]);
		v.clear();
		while (!q.empty()) {
			if (q.front()[0] == op[1]) {
				long long n = stoll(v.back());
				v.pop_back();
				q.pop();
				long long m = stoll(q.front());
				long long j = (op[1] == '*') ? n * m : (op[1] == '+') ? n + m : n - m;
				v.push_back(to_string(j));
			}
			else if (q.front()[0] != op[2])
				v.push_back(q.front());
			q.pop();
		}
		long long res = stoll(v[0]);
		for (int i = 1; i < v.size(); i++) {
			long long j = stoll(v[i]);
			res = (op[2] == '*') ? res * j : (op[2] == '+') ? res + j : res - j;
		}
		if (answer < abs(res))
			answer = abs(res);
	} while (next_permutation(op, op + 3));
	return answer;
}