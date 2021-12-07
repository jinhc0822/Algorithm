#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.06
왜 반복형 dp가 쉬운 것을 알고 있음에도 재귀를 고집했을까..
1을 포함했을 때랑 포함하지 않았을 때랑 구분하는 것은 알았는데
함수 내에서 다른 두 개의 입력이 들어오게 되니 if문이 너무 많아지게 
돼서 너무 복잡해져서 포기함. */

int cache[1000000][2];

int solution(vector<int> money) {
	int answer = 0;
	int n = money.size() - 1;
	cache[0][1] = money[0];
	cache[1][1] = money[0];
	cache[0][0] = 0;
	cache[1][0] = money[1];

	for (int i = 2; i < n; i++) {
		cache[i][1] = max(cache[i - 2][1] + money[i], cache[i - 1][1]);
		cache[i][0] = max(cache[i - 2][0] + money[i], cache[i - 1][0]);
	}
	cache[n][0] = max(cache[n - 2][0] + money[n], cache[n - 1][0]);

	return answer = max(cache[n - 1][1], cache[n][0]);
}