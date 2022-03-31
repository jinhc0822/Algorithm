#include <iostream>
#include <set>
using namespace std;

/*2022.03.31
음.. 처음에는 priority queue를 최소 최대 이렇게 두 개 가지고 어떻게 풀어보려고 했는데 방법을 찾지 못했다.
그래서 알고리즘 분류를 봤는데 이진 탐색 트리가 있길래 이것을 사용하려고 했지만 포인터를 쓴지 너무 오래된터라..
답을 봤는데 multiset을 이용한 풀이가 있었다. 처음에 deque, list 다 생각해 봤었는데 multiset도 자동으로 정렬을
해줘서 사용할 수 있는 것 같다. map은 그래도 가끔 이용하는데 set은 거의 사용을 안 해서 잊고 있었던 것 같다.
다른 풀이들을 본니까 내가 처음에 생각한 방법에 자료형을 int가 아닌 pair<int, int>를 사용해서 숫자, idx를 저장하여
푸는 방법도 있었다. visit을 사용해 그것이 이미 큐에서 사라진건지 아닌지를 판단하면서 푸는 것은 생각 못했네..*/

int t, k;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> k;
		multiset<int> ms;
		for (int i = 0; i < k; i++) {
			char c; int n;
			cin >> c >> n;
			if (c == 'I')
				ms.insert(n);
			else {
				if (ms.empty()) 
					continue;
				if (n == 1) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
				else
					ms.erase(ms.begin());
			}
		}
		if (ms.empty())
			cout << "EMPTY" << '\n';
		else {
			auto iter = ms.end();
			iter--;
			cout << *iter << ' ' << *ms.begin() << '\n';
		}
	}
}