#include <iostream>
using namespace std;

/*2021.12.29
½¬¿ò.*/

int n, sz;
string file[50], ans;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> file[i];
	ans = file[0];
	sz = file[0].length();
	for (int i = 1; i < n; i++)
		for (int j = 0; j < sz; j++)
			if (ans[j] != file[i][j])
				ans[j] = '?';
	cout << ans;
}