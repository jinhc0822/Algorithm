#include <vector>
#include <cmath>
using namespace std;

/*2022.03.01
어떤 규칙이 있는지 찾는 데에 좀 애를 먹음..
그래도 나름 괜찮은 비트연산 풀이라 생각했는데 다른 답 보니 어지럽네ㅋㅋ
다른 답을 보고 한번 생각해보는 것도 좋을 것 같다.*/

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (int i = 0; i < numbers.size(); i++) {
		if ((numbers[i] & 3) != 3)
			answer.push_back(numbers[i] + 1);
		else {
			if (((numbers[i] - 3) / 4) % 2 == 0)
				answer.push_back(numbers[i] + 2);
			else {
				int k = 0;
				while (numbers[i] & (1LL << k)) {
					k++;
				}
				answer.push_back(numbers[i] + pow(2, k - 1));
			}
		}
	}
	return answer;
}