#include <vector>
using namespace std;

/*2022.02.28
방법은 뻔히 알고 있었는데 공통인 숫자를 선택했을 때 그 짝이 될 숫자를 고르는 방법에서 막혀서 답을 봤다.
그냥 idx를 0부터 끝까지 돌리면서 선택한 숫자가 나오고 안 나왔을 때를 나눠서 생각해주면 되는 거였다...
뭔가 좀 아쉽네ㅠ..*/

int solution(vector<int> a) {
	int answer = -1;
	vector<int> cnt(a.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		cnt[a[i]]++;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] <= answer) continue;
		int res = 0;
		for (int j = 0; j < a.size() - 1; j++) {
			if (a[j] != i && a[j + 1] != i) continue;
			if (a[j] == a[j + 1]) continue;
			res++;
			j++;
		}
		if (res > answer)
			answer = res;
	}
	return answer * 2;
}