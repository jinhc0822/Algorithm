#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.10
�� ������ ����� ���� �ߴ�. �ֳ��ϸ� A�� B �迭�� �հ� C�� D �迭�� ���� 
�����ؼ� �� �����ͷ� Ǫ�� ���� ������ �����س����� (AB) + (CD) = 0�� �����ϴ� A, B, C, D��
�����ұ� �ϴ� ���� �ñ��ߴ�. ������ ������ 3���� �����µ� �� �� �ϳ��� �ص� ��� ����
�����ϰ� �ִٴ� ���� �ñ��ߴ�. �ᱹ ���ݸ� �����غ��� ������ ��� �����ϵ� ��� ���� ��ȸ�ϴ� ���̱�
������ ������ٴ� ����� ������ �ȴ�. ���ݸ� �� �����ߴ���� �ڽŰ��� ������ �����ٵ�..

�׸��� �迭�� ���� ���� ������ ���� �� �����Ƿ� ���� �����ؾ��Ѵ�. �׳� ������ Ǭ �� ������ ������δ�
��ġ�� ��찡 �ִ�. �� �κ��� ���ļ� �� ��..

�ٵ� �� ���� ���ѽð��� 12�ʳ� �ȴ�.. ������ 2�ʿ��ٰ� �ϴµ� �˰��ϱ� �ٸ� Ǯ�̵��� �̷������� 
1�ʿ� 1��� �����̶�� �����ϰ� �ϸ� �� ���ư��� �ڵ��ε� AC�� �޾Ƽ� ������ ���ҳ�����. 
�׷��� 12�ʷ� �ø��� �ϴ�. ä���ϴ� ��ǻ���� ��翡 ���� ���� ��ǻ�ʹ� 1�ʿ� 10������� ������ �� �ִٰ�
�ϴµ� Ǫ�� ���忡���� �׷� ���� �� �� ���� �����Ƿ� ���ѽð��� �ø� �� ����.*/

int n;
vector<int> A, B, C, D;
vector<int> sumAB, sumCD;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sumAB.push_back(A[i] + B[j]);
			sumCD.push_back(C[i] + D[j]);
		}
	}
	sort(sumAB.begin(), sumAB.end());
	sort(sumCD.begin(), sumCD.end());
	int sz = sumAB.size();
	int idxAB = 0, idxCD = sz - 1;
	long long ans = 0;
	while (idxAB < sz && idxCD >= 0) {
		if (sumAB[idxAB] + sumCD[idxCD] == 0) {
			int idx = idxAB;
			long long sameAB = 0, sameCD = 0;
			while (sumAB[idxAB] + sumCD[idxCD] == 0) {
				if (idxAB >= sz) break;
				sameAB++;
				idxAB++;
			}
			while (sumAB[idx] + sumCD[idxCD] == 0) {
				if (idxCD < 0) break;
				sameCD++;
				idxCD--;
			}
			ans += (sameAB * sameCD);
		}
		else if (sumAB[idxAB] + sumCD[idxCD] < 0) idxAB++;
		else idxCD--;
	}
	cout << ans;
}