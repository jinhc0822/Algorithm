#include <vector>
using namespace std;

/*2022.02.28*/

int solution(vector<int> a, vector<int> b) {
	int answer = 0;
	for (int i = 0; i < a.size(); i++)
		answer += a[i] * b[i];
	return answer;
}