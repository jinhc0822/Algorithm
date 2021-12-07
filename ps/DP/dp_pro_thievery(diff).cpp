#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.06
�� �ݺ��� dp�� ���� ���� �˰� �������� ��͸� ����������..
1�� �������� ���� �������� �ʾ��� ���� �����ϴ� ���� �˾Ҵµ�
�Լ� ������ �ٸ� �� ���� �Է��� ������ �Ǵ� if���� �ʹ� �������� 
�ż� �ʹ� ���������� ������. */

int cache[1000000][2];

int solution(vector<int> money) {
	int answer = 0;
	int n = money.size() - 1;
	cache[0][1] = money[0];
	cache[1][1] = money[0];
	cache[0][0] = 0;
	cache[1][0] = money[1];

	for (int i = 2; i < n; i++) {
		cache[i][1] = max(cache[i - 2][1] + money[i], cache[i - 1][1]);
		cache[i][0] = max(cache[i - 2][0] + money[i], cache[i - 1][0]);
	}
	cache[n][0] = max(cache[n - 2][0] + money[n], cache[n - 1][0]);

	return answer = max(cache[n - 1][1], cache[n][0]);
}