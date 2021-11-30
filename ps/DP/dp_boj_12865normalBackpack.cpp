#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*2021.11.29
�����Ͽ��� �� �� �ñ� ������ �����ϰ� ����. 
�ٵ� �̰� �ݺ��� dp�δ� ���ϰڴ�;;*/

int n, k;
pair<int, int> obj[100];
int cache[100001][100];

int pack(int capacity, int idx) {
	if (idx == n - 1) {
		if (capacity >= obj[idx].first)
			return obj[idx].second;
		else
			return 0;
	}
	int& ret = cache[capacity][idx];
	if (ret != -1) return ret;
	ret = pack(capacity, idx + 1);
	if (capacity >= obj[idx].first)
		ret = max(ret, pack(capacity - obj[idx].first, idx + 1) + obj[idx].second);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> obj[i].first >> obj[i].second;
	memset(cache, -1, sizeof(cache));
	cout << pack(k, 0);
}