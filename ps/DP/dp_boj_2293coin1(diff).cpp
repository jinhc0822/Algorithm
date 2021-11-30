#include <iostream>
#include <cstring>
using namespace std;

/*2021.11.29
���� �ݺ��� dp�� Ǯ� ����� dp�� Ǯ���� ������
��ͷ� Ǯ�� ������ �޸� ���ѿ� �ɸ��� �ȴ�... �� ������ 
�ݺ��� dp�� Ǯ �� �ۿ� ���µ�..
�� ������ �ݺ��� dp�� ���� ���̵��� �ֱ� ������ �ݺ��� dp�� Ǫ�� ���� �˾� ���� �� ���ڴ�.*/

int n, k, coin[100];
int cache[10001][100];

int price(int cur, int idx) {
	if (cur < 0) return 0;
	else if (cur == 0) return 1;
	int& ret = cache[cur][idx];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = idx; i < n; i++)
		ret += price(cur - coin[i], i);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	memset(cache, -1, sizeof(cache));
	cout << price(k, 0) << '\n';
}