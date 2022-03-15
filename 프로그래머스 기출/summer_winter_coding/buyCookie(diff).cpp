#include <vector>
using namespace std;

/*2022.03.14
부분합으로 풀려고 했음. 처음에는 완전탐색 하려다가 그 경우의 수가 13억 정도 되서 포기.
그래서 투포인터 같은 느낌으로 풀 수 있지 않을까 생각했음.
근데 만약 left>right일 경우에 l을 증가시켜야할지 r을 증가시켜야할지 확실하지 않다는 문제가 있었다.
결국 답지를 봤는데 이런 방법이 있을 줄이야.. 투포인터 방식 비슷하긴한데 접근 방식이 다르다.. ㅜ
문제를 풀다보면 너무 순차적으로하려는 성향이 있어 잘못된 접근을 하는 경우가 많은 것 같다.*/

int solution(vector<int> cookie) {
	int answer = 0, n = cookie.size();
	if (n == 1)
		return 0;
	if (n == 2) {
		if (cookie[0] == cookie[1]) return cookie[0];
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int leftIdx = i;
		int rightIdx = i + 1;
		int leftSum = cookie[leftIdx];
		int rightSum = cookie[rightIdx];
		while (true) {
			if (leftSum == rightSum)
				if (answer < leftSum)
					answer = leftSum;
			if (leftIdx > 0 && leftSum <= rightSum) {
				leftIdx--;
				leftSum += cookie[leftIdx];
			}
			else if (rightIdx < n - 1 && rightSum <= leftSum) {
				rightIdx++;
				rightSum += cookie[rightIdx];
			}
			else break;
		}
	}
	return answer;
}