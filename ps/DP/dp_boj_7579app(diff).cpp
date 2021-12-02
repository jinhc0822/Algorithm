#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*2021.12.02
��ͷ� Ǯ�� �; ��� �����غôµ� �������. �Դٰ� �� �ϴ���� dp[i][j]����
i�� index, j�� �޸�ũ��� �ߴ��� �翬�� �迭 ũ�� �ʰ��� ���� ���ͳ��� ������ �޾Ұ�
�׷��� �ּ� ����� ���ϴ� ������ �������� �ʾ� ���� �ô�. while���� �������� ���� ����̾���.
Ȯ���� �̷� ������ ��ȭ���� ���ؼ� �ݺ��� dp�� Ǫ�� ���� ���� �� ����.*/

int n, m, memory[101], cost[101];
int cache[101][10001];

int f(int idx, int sumC) {
	if (idx == n) return 0;
	int& ret = cache[idx][sumC];
	if (ret != -1) return ret;
	ret = f(idx + 1, sumC);
	if (cost[idx] <= sumC) 
		ret = max(ret, memory[idx] + f(idx + 1, sumC - cost[idx]));
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int totalC = 0;
	while (true) {
		if (f(0, totalC) >= m)
			break;
		totalC++;
	}
	cout << totalC;
}