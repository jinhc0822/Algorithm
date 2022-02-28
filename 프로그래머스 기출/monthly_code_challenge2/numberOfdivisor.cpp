#include <vector>
using namespace std;

/*2022.02.28*/

int solution(int left, int right) {
	int answer = 0;
	vector<int> cnt(right + 1, 1);
	for (int i = 2; i < cnt.size(); i++) {
		int k = 1;
		while (i * k <= right) {
			cnt[i * k]++;
			k++;
		}
	}
	for (int i = left; i <= right; i++) {
		if (cnt[i] % 2 == 0) answer += i;
		else answer -= i;
	}
	return answer;
}