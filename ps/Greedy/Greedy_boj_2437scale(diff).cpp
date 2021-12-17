#include <iostream>
#include <algorithm>
using namespace std;

/*2021.12.16
예전에도 풀지 못했던 문제. 이번에는 답에 거의 가깝게 생각했는데
그것을 수식으로 풀지 못해 못 풀었다. 문제의 메모에 있는 링크에서 설명한대로
잴 수 있는 무게와 이 전 무게를 헷갈려서 분명 직관적으로 생각하면 맞는데 
자세히 들여다 보면 아닌 것 같은 생각이 반복되면서 포기... 조금 아쉽다.*/

int n, w[1000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w, w + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 >= w[i]) sum += w[i];
		else break;
	}
	cout << sum + 1;
}