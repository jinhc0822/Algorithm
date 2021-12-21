#include <iostream>
using namespace std;

/*2021.12.21
���ͳ��� �ڵ带 �״�� �����Դ�. �Ǽ��� �޸� Ȯ���ع����� �ٶ��� ������ �ܸ��� ���� 
������ ���ع��ȴ�. �׷��� ���� ������ �ƴ� �� ����.
����� ���� �� �������Ѵ�. �� �� ���� �߿��� ����Ʈ�� ���� ��Ƽ���� ���� ���¿���
��Ƽ�ǿ� ���� ��⸦ ���ƾ��ϴ� ��� ���� ���߿� �ٽ� ���ǰų� ���� ����� ���� ����
��⸦ ã�� ���̴�. �̰��� ������ �ڵ尡 ����� �� ��Ư�ϴ�. �ٽ� Ǯ����� ����.*/

int n, k;
int schedule[101], plug[101];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> schedule[i];
	int ans = 0;
	for (int i = 0; i < k; i++) {
		bool pluggedIn = false;
		// �̹� ��Ƽ�ǿ� �����ִ� ���
		for (int j = 0; j < n; j++)
			if (plug[j] == schedule[i]) {
				pluggedIn = true;
				break;
			}
		if (pluggedIn) continue;
		// ��Ƽ�ǿ� ������� ĭ�� ���� ���
		for (int j = 0; j < n; j++)
			if (!plug[j]) {
				plug[j] = schedule[i];
				pluggedIn = true;
				break;
			}
		if (pluggedIn) continue;
		// ���� ���߿� �ٽ� ���ǰų� ������ ������ �ʴ� ��� ã��
		int idx, deviceIdx = -1;
		for (int j = 0; j < n; j++) {
			int lastIdx = 0;
			for (int r = i + 1; r < k; r++) {
				if (plug[j] == schedule[r]) break;
				lastIdx++;
			}
			if (lastIdx > deviceIdx) {
				idx = j;
				deviceIdx = lastIdx;
			}
		}
		ans++;
		plug[idx] = schedule[i];
	}
	cout << ans;
}