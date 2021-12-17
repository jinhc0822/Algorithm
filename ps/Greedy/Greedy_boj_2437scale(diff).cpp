#include <iostream>
#include <algorithm>
using namespace std;

/*2021.12.16
�������� Ǯ�� ���ߴ� ����. �̹����� �信 ���� ������ �����ߴµ�
�װ��� �������� Ǯ�� ���� �� Ǯ����. ������ �޸� �ִ� ��ũ���� �����Ѵ��
�� �� �ִ� ���Կ� �� �� ���Ը� �򰥷��� �и� ���������� �����ϸ� �´µ� 
�ڼ��� �鿩�� ���� �ƴ� �� ���� ������ �ݺ��Ǹ鼭 ����... ���� �ƽ���.*/

int n, w[1000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w, w + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 >= w[i]) sum += w[i];
		else break;
	}
	cout << sum + 1;
}