#include <iostream>
#include <set>
using namespace std;

/*2022.03.31
��.. ó������ priority queue�� �ּ� �ִ� �̷��� �� �� ������ ��� Ǯ����� �ߴµ� ����� ã�� ���ߴ�.
�׷��� �˰��� �з��� �ôµ� ���� Ž�� Ʈ���� �ֱ淡 �̰��� ����Ϸ��� ������ �����͸� ���� �ʹ� �������Ͷ�..
���� �ôµ� multiset�� �̿��� Ǯ�̰� �־���. ó���� deque, list �� ������ �þ��µ� multiset�� �ڵ����� ������
���༭ ����� �� �ִ� �� ����. map�� �׷��� ���� �̿��ϴµ� set�� ���� ����� �� �ؼ� �ذ� �־��� �� ����.
�ٸ� Ǯ�̵��� ���ϱ� ���� ó���� ������ ����� �ڷ����� int�� �ƴ� pair<int, int>�� ����ؼ� ����, idx�� �����Ͽ�
Ǫ�� ����� �־���. visit�� ����� �װ��� �̹� ť���� ��������� �ƴ����� �Ǵ��ϸ鼭 Ǫ�� ���� ���� ���߳�..*/

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