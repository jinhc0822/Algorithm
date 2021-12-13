#include <iostream>
#define MAX 93001
using namespace std;

/*2021.12.13
어 음.. 이게 왜 그리디일까..
일단 쉬움. MAX를 저렇게 정한 이유는 93000까지의 합이 43억이었기 때문*/

long long pSum[MAX];
long long S;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> S;
	for (int i = 1; i < MAX; i++) {
		pSum[i] = pSum[i - 1] + i;
		if (pSum[i] > S) {
			cout << i - 1;
			return 0;
		}
	}
}