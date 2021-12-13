#include <iostream>
#include <algorithm>
using namespace std;

/*2021.12.13
쉬웠다. 종만북에 나온대로 정당성을 확인해보자.
B의 숫자가 i번째로 작은 수라면 A의 숫자는 i번째로 큰 숫자여야 S가 최소가 된다.
만약 B의 숫자에 대응되는 A의 숫자가 i번째로 큰 숫자 a보다 작은 숫자 x라 할 경우
x가 a보다 작다는 것을 이용하면 원래의 가정이 최적해임을 알 수 있다. 예시로 해보면 
이해 쉬움ㅇㅇ..*/

int n, A[50], B[50], ans;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	sort(B, B + n);
	sort(A, A + n, greater<int>());
	for (int i = 0; i < n; i++)
		ans += A[i] * B[i];
	cout << ans;
}