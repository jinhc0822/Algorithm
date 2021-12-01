#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*2021.11.30
-1로 하는 게 좀 헷갈려서 배열을 뒤로 한칸씩 밀고 A[0]=0을 줬음.*/

int n, A[1001];
int cache[1001];

int bis(int cur) {
	if (cur == n) return A[cur];
	int& ret = cache[cur];
	if (ret != -1) return ret;
	ret = A[cur];
	for (int next = cur + 1; next <= n; next++)
		if (A[next] > A[cur])
			ret = max(ret, bis(next) + A[cur]);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	A[0] = 0;
	memset(cache, -1, sizeof(cache));
	cout << bis(0);
}