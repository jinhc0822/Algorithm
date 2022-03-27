#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*2022.03.27
처음에 bfs로 하려고 했는데 시간초과 나올거 같았는데 메모리 초과가 나옴.. 근데 이거 왜 테스트 케이스 개수 안나옴..
아마 메모리를 최악의 경우 테스트 케이스마다 21억개 이상 사용하려다 보니 나온 것 같음.
그래서 규칙성이 있나 찾아본 결과 있긴 있었음. 어차피 증가해야하니까 12321 1234321처럼 규칙을 가진 수에 초점을 두고
어떤 식으로 이동하는지 관찰해본 결과 21-27의 코드가 나왔음. 근데 다른 방법도 있긴 하더라.. 아니 근데 중간 중간에
코드 짜는 거 때문에 시간이 좀 많이 걸렸다.. ㅜ*/

int t, x, y;
vector<long long> v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	v.push_back(0);
	long long k = 0, tmp = 1, i = 1;
	while (true) {
		k = k + tmp;
		if (k > INT_MAX) break;
		v.push_back(k);
		if (i % 2 == 0) tmp++;
		i++;
	}
	while (t--) {
		cin >> x >> y;
		int diff = y - x;
		for (i = 0; i < v.size(); i++) {
			if (v[i] == diff) {
				cout << i << '\n';
				break;
			}
			else if (v[i] > diff) {
				cout << i << '\n';
				break;
			}
		}
		if (i == v.size())
			cout << v.size() << '\n';
	}
}