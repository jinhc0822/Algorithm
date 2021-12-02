#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*2021.12.02
재귀로 풀고 싶어서 계속 도전해봤는데 어려웠다. 게다가 늘 하던대로 dp[i][j]에서
i를 index, j를 메모리크기로 했더니 당연히 배열 크기 초과가 나서 인터넷의 도움을 받았고
그래도 최소 비용을 구하는 로직이 떠오르지 않아 답을 봤다. while문은 생각하지 못한 방법이었다.
확실히 이런 문제는 점화식을 구해서 반복적 dp로 푸는 것이 좋을 거 같다.*/

int n, m, memory[101], cost[101];
int cache[101][10001];

int f(int idx, int sumC) {
	if (idx == n) return 0;
	int& ret = cache[idx][sumC];
	if (ret != -1) return ret;
	ret = f(idx + 1, sumC);
	if (cost[idx] <= sumC) 
		ret = max(ret, memory[idx] + f(idx + 1, sumC - cost[idx]));
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int totalC = 0;
	while (true) {
		if (f(0, totalC) >= m)
			break;
		totalC++;
	}
	cout << totalC;
}