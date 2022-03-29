#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*2022.03.29
����Ž������ Ǯ�� �翬�� �ð��ʰ��� �ɸ��Ƿ� �پ��� ����� �����ߴµ� �� ������� �ݷʰ� �ϳ����� �־
������ Ǯ�� ����� ã�� ���ϴٰ� �˰��� �з��� �ô�.
�����̶� ���� ���ڸ��� �����ϰ� �ذ�.. �׷��� �ܼ��� ���ù����� �ƴϰ� ���� ������ �ؾ��ϴ� ��������.*/

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