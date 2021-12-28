#include <iostream>
using namespace std;

/*2021.12.28
kmp �˰����� table ����� ����� ����ؼ� Ǫ�� ����.
����� ����� kmp �˰���� �ſ� �����ϴ�. 
�������� ��Ģ�� ���� ���� ����߳�;; �ϴ� ���ϱ� ���ݰ� ��.
������ �� ������ table[sz-1]�� ���� ���� �߿��ϴٴ°���..*/

int L, table[1000000];
string s;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> L >> s;
	int sz = s.length();
	for (int i = 1, j = 0; i < sz; i++) {
		while (j > 0 && s[i] != s[j])
			j = table[j - 1];
		if (s[i] == s[j])
			table[i] = ++j;
	}
	cout << sz - table[sz - 1];
}