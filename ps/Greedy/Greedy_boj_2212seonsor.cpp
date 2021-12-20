#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.20
�� ������ ����... ó������ ���� ������ �Ÿ��� �����ؼ� ū ������� 
k-1���� �߶󳻸� ���� ������ �ϰ� �����ߴµ� �׷��� �ϸ� �ȵǴ� ��찡 �־���. 
�׷��� �ᱹ ���� �ôµ� �� Ǯ�� ����� �¾Ұ� �Ʊ� Ȯ���ϴ� �������� �ణ �Ǽ���
�־��� ����. �� ���� Ȯ���غ��� ����?.. �ణ ��Ż�ϱ� �ϳ�.. ��° ������� �������..*/

int n, k, ans;
int sensor[10001], dist[10001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> sensor[i];
	sort(sensor, sensor + n);
	for (int i = 0; i < n - 1; i++)
		dist[i] = sensor[i + 1] - sensor[i];
	sort(dist, dist + n - 1);
	for (int i = 0; i < n - k; i++)
		ans += dist[i];
	cout << ans;
}