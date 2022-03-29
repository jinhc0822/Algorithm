#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*2022.03.29
완전탐색으로 풀면 당연히 시간초과가 걸리므로 다양한 방법을 생각했는데 각 방법마다 반례가 하나씩은 있어서
마땅히 풀이 방법을 찾지 못하다가 알고리즘 분류를 봤다.
스택이란 것을 보자마자 수월하게 해결.. 그래도 단순한 스택문제는 아니고 조금 응용을 해야하는 문제였다.*/

int n;
vector<int> tower, answer;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	tower.resize(n);
	answer.resize(n);
	for (int i = 0; i < n; i++)
		cin >> tower[i];
	int idx = n - 2;
	stack<pair<int, int>> s;
	s.push({ tower[n - 1], n - 1 });
	while (idx >= 0) {
		while (!s.empty() && s.top().first <= tower[idx]) {
			if (s.empty()) break;
			answer[s.top().second] = idx + 1;
			s.pop();
		}
		s.push({ tower[idx], idx });
		idx--;
	}
	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
}