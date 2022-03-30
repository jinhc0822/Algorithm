#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*2022.03.30
어제 푼 2493번 문제와 똑같음.*/

int n;
vector<int> A, answer;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	A.resize(n);
	answer.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int idx = 1;
	stack<pair<int, int>> s;
	s.push({ A[0], 0 });
	while (idx < n) {
		while (!s.empty() && s.top().first < A[idx]) {
			if (s.empty()) break;
			answer[s.top().second] = A[idx];
			s.pop();
		}
		s.push({ A[idx], idx });
		idx++;
	}
	for (int i = 0; i < n; i++) {
		if (answer[i] == 0) cout << -1 << ' ';
		else cout << answer[i] << ' ';
	}
}