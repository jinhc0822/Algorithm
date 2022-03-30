#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*2022.03.30
그냥 하면 풀림..*/

int n, k;
bool alphabet[26];
vector<string> str;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	str.resize(n);
	string base = "antic";
	for (int i = 0; i < 5; i++)
		alphabet[base[i] - 'a'] = true;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++)
			if (!alphabet[s[j] - 'a'])
				str[i].push_back(s[j]);
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < 5; i++)
		alphabet[base[i] - 'a'] = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < str[i].size(); j++)
			alphabet[str[i][j] - 'a'] = true;
	vector<int> v;
	for (int i = 0; i < 26; i++)
		if (alphabet[i])
			v.push_back(i);
	vector<bool> b(v.size(), true);
	int cnt = k - 5;
	if (v.size() <= cnt) {
		cout << n;
		return 0;
	}
	for (int i = 0; i < b.size() - cnt; i++)
		b[i] = false;
	int answer = 0;
	do {
		int res = 0;
		for (int i = 0; i < v.size(); i++)
			if (b[i])
				alphabet[v[i]] = false;
		for (int i = 0; i < n; i++) {
			bool chk = true;
			for (int j = 0; j < str[i].size(); j++) {
				if (alphabet[str[i][j] - 'a']) {
					chk = false;
					break;
				}
			}
			if (chk) res++;
		}
		for (int i = 0; i < v.size(); i++)
			if (b[i])
				alphabet[v[i]] = true;
		if (answer < res)
			answer = res;
	} while (next_permutation(b.begin(), b.end()));
	cout << answer;
}