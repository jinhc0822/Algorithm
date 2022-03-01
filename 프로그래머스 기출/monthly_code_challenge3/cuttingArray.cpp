#include <vector>
using namespace std;

/*2022.03.01
규칙 좀 헷갈려하면서 구했긴 한데 
다른 답을 보니 그냥 max(i/n, i%n)+1을 answer에 넣으면 된다고 하네..*/

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