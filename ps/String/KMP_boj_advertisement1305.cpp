#include <iostream>
using namespace std;

/*2021.12.28
kmp 알고리즘의 table 만드는 방법을 사용해서 푸는 문제.
만드는 방법은 kmp 알고리즘과 매우 유사하다. 
문제에서 규칙이 뭘까 한참 고민했네;; 하다 보니까 깨닫게 됨.
어차피 맨 마지막 table[sz-1]의 값이 제일 중요하다는것을..*/

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