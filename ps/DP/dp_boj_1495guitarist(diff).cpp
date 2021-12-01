#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*2021.12.01
bool로 깃발 만들어서 확인하는 거에 신경을 쓰다가 더 쉬운 방법을 놓치고 말았다.
이렇게 경우의 수가 아닌 최댓값을 구하는 것에 조금 약한듯.*/
int n, s, m, v[50];
int cache[50][1001];

int volume(int idx, int curV) {
	if (curV<0 || curV>m) return -1000000;
	if (idx == n) return curV;
	int& ret = cache[idx][curV];
	if (ret != -1) return ret;
	ret = 0;
	ret += max(volume(idx + 1, curV + v[idx]), volume(idx + 1, curV - v[idx]));
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	memset(cache, -1, sizeof(cache));
	int ans = volume(0, s);
	if (ans < 0) cout << -1;
	else cout << ans;
}