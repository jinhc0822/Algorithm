#include <iostream>
using namespace std;

/*2021.12.08
�׳� �⺻���� �����̵� ������ ����.. ����..*/

int n, k;
int ice[1000000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	int m = 0; // ���� ��ǥ�� ū ���� �ִ� �絿��
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (b > m) m = b;
		ice[b] = a;
	}
	int start = 0, end = (2 * k > m) ? m : 2 * k;
	int sum = 0, ans = 0;;
	for (int i = start; i <= end; i++)
		sum += ice[i];
	ans = sum;
	start++; end++;
	while (end <= m) {
		sum -= ice[start - 1];
		sum += ice[end];
		if (sum > ans) ans = sum;
		start++; end++;
	}
	cout << ans;
}