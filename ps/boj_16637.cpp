#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*2022.03.22
���α׷��ӽ��� �ִ� ��Ģ���� ������ ���� �Ȱ��� �������� �˾Ҵµ� ������ ������ �տ������� �ؾ��ϰ�
��ȣ�� ��ø�� �ȵż� �� �� �ۿ� ���� ���Ѵٴ� ������ �־� ������ �ٸ� ��������...
������ �����ε� ���� �ð��� �ɷȳ�. ������� ������ �ϱ� ������ ���� ������ �ٷ� �ϴ� �Ͱ�
���� ������ ���� ���� ���ݰŶ� ����ϴ� ���, �̷��� 2�����ۿ� ���µ� �̰� ��� ���ٱ� ���� ����� �ߴ�.
ac Ǯ�̴� ���� ����å���� ������ Ǯ�̿��µ� �̰� ������ �����̾���. ó������ dfs �μ��� bool�� �༭
���� ������ ��ȣ�� �������� �ƴ��� ǥ�ø� ������µ� �ʹ� ���������� �����ߴ�.*/

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