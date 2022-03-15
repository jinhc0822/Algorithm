#include <vector>
using namespace std;

/*2022.03.14
�κ������� Ǯ���� ����. ó������ ����Ž�� �Ϸ��ٰ� �� ����� ���� 13�� ���� �Ǽ� ����.
�׷��� �������� ���� �������� Ǯ �� ���� ������ ��������.
�ٵ� ���� left>right�� ��쿡 l�� �������Ѿ����� r�� �������Ѿ����� Ȯ������ �ʴٴ� ������ �־���.
�ᱹ ������ �ôµ� �̷� ����� ���� ���̾�.. �������� ��� ����ϱ��ѵ� ���� ����� �ٸ���.. ��
������ Ǯ�ٺ��� �ʹ� �����������Ϸ��� ������ �־� �߸��� ������ �ϴ� ��찡 ���� �� ����.*/

int solution(vector<int> cookie) {
	int answer = 0, n = cookie.size();
	if (n == 1)
		return 0;
	if (n == 2) {
		if (cookie[0] == cookie[1]) return cookie[0];
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int leftIdx = i;
		int rightIdx = i + 1;
		int leftSum = cookie[leftIdx];
		int rightSum = cookie[rightIdx];
		while (true) {
			if (leftSum == rightSum)
				if (answer < leftSum)
					answer = leftSum;
			if (leftIdx > 0 && leftSum <= rightSum) {
				leftIdx--;
				leftSum += cookie[leftIdx];
			}
			else if (rightIdx < n - 1 && rightSum <= leftSum) {
				rightIdx++;
				rightSum += cookie[rightIdx];
			}
			else break;
		}
	}
	return answer;
}