#include <vector>
using namespace std;

/*2022.03.01
��Ģ �� �򰥷��ϸ鼭 ���߱� �ѵ� 
�ٸ� ���� ���� �׳� max(i/n, i%n)+1�� answer�� ������ �ȴٰ� �ϳ�..*/

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	for (long long i = left; i <= right; i++) {
		int k = i / n + 1;
		if (i % n < k)
			answer.push_back(k);
		else
			answer.push_back(k + (i % n - k) + 1);
	}
	return answer;
}