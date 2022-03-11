#include <vector>
using namespace std;

/*2022.03.11
그냥 생각한대로 구현하면 풀림. 구현도 쉬움..
무슨 유형의 문제인지 잘 모르겠다. 그리디인가?..*/

int solution(int n, vector<int> stations, int w) {
	int answer = 0;
	int k = w * 2 + 1;
	int s = 0, e = 0;
	for (int i = 0; i < stations.size(); i++) {
		e = stations[i] - w;
		if (e - s - 1 > 0) {
			answer += (e - s - 1) / k ;
			if ((e - s - 1) % k != 0) answer++;
		}
		s = stations[i] + w;
	}
	if (s < n) {
		answer += (n - s) / k;
		if ((n - s) % k != 0) answer++;
	}
	return answer;
}