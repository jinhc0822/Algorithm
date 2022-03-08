#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.07
항상 이분탐색에 약한 것 같다.. 이 문제도 처음에 배낭 문제인가 싶었는데 
결국 푸는 방법을 모르겠어서 답을 봤다.
최소 시간을 구하는 문제에서 시간을 정해놓고 그 시간 이내에 옮길 수 있을까 하는 생각을 바탕으로
모든 시간에 대해서(모든 시간을 불가능하니 이분탐색 사용) 확인해보는 방법은 예전 백준 문제에서도 한 번 본 것 같다..
search 함수를 눈여겨보자
아.. 왜 이 생각을 못했지.. 처음에 배낭문제라 생각하고 거기에서 막힌게 못 푼 큰 원인인 것 같다. 애초에
이 문제는 차례대로 해결하는 문제가 아닌데 왜 배낭문제라고 생각했지.. 후..*/

bool search(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid) {
	long long totG = 0;
	long long totS = 0;
	long long tot = 0;
	for (int i = 0; i < g.size(); i++) {
		long long time = t[i];
		long long roundT = time * 2;
		long long move = mid / roundT;
		if (mid % roundT >= time) move++;
		long long maxTake = w[i] * move;

		totG += min((long long)g[i], maxTake);
		totS += min((long long)s[i], maxTake);
		tot += min((long long)g[i] + s[i], maxTake);
	}
	if (totG >= a && totS >= b && tot >= a + b) return true;
	else return false;
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = -1;
	long long left = 0;
	long long right = 10e15;
	answer = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (search(a, b, g, s, w, t, mid)) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return answer;
}