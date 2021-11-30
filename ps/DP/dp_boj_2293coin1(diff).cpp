#include <iostream>
#include <cstring>
using namespace std;

/*2021.11.29
전에 반복적 dp로 풀어서 재귀적 dp로 풀려고 했지만
재귀로 풀면 무조건 메모리 제한에 걸리게 된다... 이 문제는 
반복적 dp로 풀 수 밖에 없는듯..
이 문제는 반복적 dp도 조금 난이도가 있기 때문에 반복적 dp로 푸는 것을 알아 놓는 게 좋겠다.*/

int n, k, coin[100];
int cache[10001][100];

int price(int cur, int idx) {
	if (cur < 0) return 0;
	else if (cur == 0) return 1;
	int& ret = cache[cur][idx];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = idx; i < n; i++)
		ret += price(cur - coin[i], i);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	memset(cache, -1, sizeof(cache));
	cout << price(k, 0) << '\n';
}