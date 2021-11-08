#include <iostream>
#define MAX 1000001
using namespace std;

/*2021.11.08
전의 코드가 더 나은 것 같다... 북마크되어있는걸로 봐서는
다른 사람 코드를 참고한 거 같긴한데.*/

int cache[MAX];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 2; i < MAX; i++)
		cache[i] = MAX + 1;
	cache[1] = 0;
	for (int i = 1; i < MAX - 1; i++) {
		if (i + 1 < MAX && cache[i + 1] > cache[i] + 1) 
			cache[i + 1] = cache[i] + 1;
		if (i * 3 < MAX && cache[i * 3] > cache[i] + 1)
			cache[i * 3] = cache[i] + 1;
		if (i * 2 < MAX && cache[i * 2] > cache[i] + 1)
			cache[i * 2] = cache[i] + 1;
	}
	int n; cin >> n;
	cout << cache[n];
}