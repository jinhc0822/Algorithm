#include <vector>
using namespace std;

/*2022.02.28
����� ���� �˰� �־��µ� ������ ���ڸ� �������� �� �� ¦�� �� ���ڸ� ���� ������� ������ ���� �ô�.
�׳� idx�� 0���� ������ �����鼭 ������ ���ڰ� ������ �� ������ ���� ������ �������ָ� �Ǵ� �ſ���...
���� �� �ƽ��פ�..*/

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