#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*2021.11.29
��������� Ǯ�� ���� ����� �Ͽ����� ����� ã�� ���ߴ�.
���ͳ����� ã��.. ����ϴٰ� ������ �ʹ� ȥ�������� �׸���.*/

string A, B;
int lenA, lenB;
int cache[1001][1001];

int lcs(int idxA, int idxB) {
	int& ret = cache[idxA][idxB];
	if (ret != -1)
		return ret;
	if (idxA >= lenA || idxB >= lenB)
		return 0;
	if (idxA == lenA - 1 && idxB == lenB - 1) {
		ret = (A[idxA] == B[idxB]);
		return ret;
	}
	if (A[idxA] == B[idxB])
		ret = lcs(idxA + 1, idxB + 1) + 1;
	else
		ret = max(lcs(idxA + 1, idxB), lcs(idxA, idxB + 1));
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> A >> B;
	lenA = A.length(); lenB = B.length();
	memset(cache, -1, sizeof(cache));
	cout << lcs(0, 0);
}