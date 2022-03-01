#include <vector>
#include <cmath>
using namespace std;

/*2022.03.01
� ��Ģ�� �ִ��� ã�� ���� �� �ָ� ����..
�׷��� ���� ������ ��Ʈ���� Ǯ�̶� �����ߴµ� �ٸ� �� ���� �������פ���
�ٸ� ���� ���� �ѹ� �����غ��� �͵� ���� �� ����.*/

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