#include <string>
#include <vector>
using namespace std;

/*2022.01.25
�ʹݿ� ��� ¥������ �� ����� �߱� �ѵ� dfs�� ������ ��ü ������ �� ���ߴ�.
�ٵ� īī�� ���� �ؼ��� ���� �׳� ���� ��ȯ���� Ǯ� �����ߴ� �� ����. ���� �� ������ �� �� ���� �ƴ����� 
������ ���ڴ� 1�� �ö󰡼� ��û �����ѵ� ���� �� ������ȯ ����� ���� ���غ��� ����� �����.*/

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
	// i�� ������ 16�� ������ 10���� ��ü ���ӿ� ���ؾ��ϴ� ���� ���� �����ε� ���� �ڸ����� �ö� Ȯ���� ū 2������ �� �� ������ 2�� 14-15�� ������.
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