#include <iostream>
#include <set>
using namespace std;

/*2021.12.27
�ߺ� üũ �����Ƽ� set�� ����ߴµ� set�� �̷� ������ �ִٴ� ���� ó�� �˾���...
set, map�� �⺻������ �������� �����̱� ������ ������ ���Ƿ� �����Ϸ��� ���ڿ� ����ü ���Ŀ�
�����ڸ� �߰��ؼ� �� �� �ִ�.*/

struct Comp {
	bool operator() (string a, string b) const{
		if (a.length() != b.length())
			return a.length() < b.length();
		else
			return a < b;
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;  cin >> n;
	set<string, Comp> st;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		st.insert(s);
	}
	for (auto iter : st)
		cout << iter << '\n';
}