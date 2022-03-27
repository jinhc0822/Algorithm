#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*2022.03.27
ó���� bfs�� �Ϸ��� �ߴµ� �ð��ʰ� ���ð� ���Ҵµ� �޸� �ʰ��� ����.. �ٵ� �̰� �� �׽�Ʈ ���̽� ���� �ȳ���..
�Ƹ� �޸𸮸� �־��� ��� �׽�Ʈ ���̽����� 21�ﰳ �̻� ����Ϸ��� ���� ���� �� ����.
�׷��� ��Ģ���� �ֳ� ã�ƺ� ��� �ֱ� �־���. ������ �����ؾ��ϴϱ� 12321 1234321ó�� ��Ģ�� ���� ���� ������ �ΰ�
� ������ �̵��ϴ��� �����غ� ��� 21-27�� �ڵ尡 ������. �ٵ� �ٸ� ����� �ֱ� �ϴ���.. �ƴ� �ٵ� �߰� �߰���
�ڵ� ¥�� �� ������ �ð��� �� ���� �ɷȴ�.. ��*/

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