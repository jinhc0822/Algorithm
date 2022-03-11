#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.11
흔한 그리디 알고리즘 문제*/

int solution(vector<int> A, vector<int> B) {
	int score = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int idxA = 0, idxB = 0;
	while (idxA < A.size() && idxB < B.size()) {
		if (A[idxA] >= B[idxB])
			idxB++;
		else {
			score++;
			idxA++; idxB++;
		}
	}
	return score;
}