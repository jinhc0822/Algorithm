#include <iostream>
using namespace std;

/*2021.12.28
기본적인 kmp 문제 
https://gusdnd852.tistory.com/172 정말 설명이 좋다.*/

int table[1000000], w, p;
string wh, pat;

void lps() {
	for (int i = 1, j = 0; i < p; i++) {
		while (j > 0 && pat[i] != pat[j])
			j = table[j - 1];
		if (pat[i] == pat[j])
			table[i] = ++j;
	}
}
bool kmp() {
	for (int i = 0, j = 0; i < w; i++) {
		while (j > 0 && wh[i] != pat[j])
			j = table[j - 1];
		if (wh[i] == pat[j]) {
			if (j == p - 1)
				return true;
			else
				j++;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> wh >> pat;
	w = wh.length();
	p = pat.length();
	lps();
	if (kmp()) cout << 1;
	else cout << 0;
}