#include <iostream>
#include <set>
using namespace std;

/*2021.12.27
중복 체크 귀찮아서 set을 사용했는데 set에 이런 사용법이 있다는 것을 처음 알았음...
set, map은 기본적으로 오름차순 정렬이기 때문에 정렬을 임의로 조정하려면 인자에 구조체 형식에
연산자를 추가해서 할 수 있다.*/

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