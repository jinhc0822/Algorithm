#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

/*2021.11.30
이 문제는 해결 방법을 찾지 못했다..
무엇이 부분문제인지 파악을 잘 하고 cache 배열을 2차원으로 할지 1차원으로 할지
정했어야하는데 부분문제 찾는 것조차 하지 못했다. */

struct Matrix {
	int r, c;
};
int n, cache[500][500];
Matrix mat[500];

int multi(int s, int e) {
	int& ret = cache[s][e];
	if (s == e) return 0;
	if (ret != -1) return ret;
	ret = INT_MAX;
	for (int i = s; i < e; i++)
		ret = min(ret, multi(s, i) + multi(i + 1, e) + mat[s].r * mat[i].c * mat[e].c);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i].r >> mat[i].c;
	memset(cache, -1, sizeof(cache));
	cout << multi(0, n - 1);
}