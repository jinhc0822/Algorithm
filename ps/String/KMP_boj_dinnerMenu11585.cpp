#include <iostream>
using namespace std;

/*2021.12.29
KMP문제.*/

int n, table[1000000];
string roulette, meat;

void lps() {
	int sz = meat.length();
	for (int i = 1, j = 0; i < sz; i++) {
		while (j > 0 && meat[i] != meat[j])
			j = table[j - 1];
		if (meat[i] == meat[j])
			table[i] = ++j;
	}
}
int kmp() {
	int rSz = roulette.length();
	int mSz = meat.length();
	int cnt = 0;
	for (int i = 0, j = 0; i < rSz - 1; i++) {
		while (j > 0 && roulette[i] != meat[j])
			j = table[j - 1];
		if (roulette[i] == meat[j]) {
			if (j == mSz - 1) {
				cnt++;
				j = table[j];
			}
			else
				j++;
		}
	}
	return cnt;
}
int gcd(int a, int b) {
	while (true) {
		int tmp = b;
		b = a % b;
		a = tmp;
		if (b == 0) break;
	}
	return a;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a; cin >> a;
		meat += a;
	}
	for (int i = 0; i < n; i++) {
		char a; cin >> a;
		roulette += a;
	}
	roulette += roulette;
	lps();
	int cnt = kmp();
	int d = gcd(cnt, n);
	cout << cnt / d << '/' << n / d;
}