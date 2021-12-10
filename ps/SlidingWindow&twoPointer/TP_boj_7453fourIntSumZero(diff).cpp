#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.10
이 문제는 고민을 조금 했다. 왜냐하면 A와 B 배열의 합과 C와 D 배열의 합을 
정렬해서 투 포인터로 푸는 것은 빠르게 생각해냈지만 (AB) + (CD) = 0을 만족하는 A, B, C, D가
유일할까 하는 점이 궁금했다. 집합의 결합이 3가지 나오는데 그 중 하나만 해도 모든 답을
포함하고 있다는 것이 궁금했다. 결국 조금만 생각해보면 집합을 어떻게 결합하든 모든 답을 순회하는 것이기
때문에 상관없다는 결론이 나오게 된다. 조금만 더 생각했더라면 자신감을 가지고 했을텐데..

그리고 배열에 같은 값을 가지고 있을 수 있으므로 조금 주의해야한다. 그냥 저번에 푼 투 포인터 방법으로는
놓치는 경우가 있다. 이 부분을 놓쳐서 답 봄..

근데 이 문제 제한시간이 12초나 된다.. 원래는 2초였다고 하는데 알고보니까 다른 풀이들이 이론적으로 
1초에 1억번 연산이라고 생각하고 하면 안 돌아가는 코드인데 AC를 받아서 질문이 많았나보다. 
그래서 12초로 늘린듯 하다. 채점하는 컴퓨터의 사양에 따라 요즘 컴퓨터는 1초에 10억번까지 연산할 수 있다고
하는데 푸는 입장에서는 그런 것을 다 알 수는 없으므로 제한시간을 늘린 것 같다.*/

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