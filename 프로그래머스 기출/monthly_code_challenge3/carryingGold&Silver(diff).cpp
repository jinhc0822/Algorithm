#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.07
�׻� �̺�Ž���� ���� �� ����.. �� ������ ó���� �賶 �����ΰ� �;��µ� 
�ᱹ Ǫ�� ����� �𸣰ھ ���� �ô�.
�ּ� �ð��� ���ϴ� �������� �ð��� ���س��� �� �ð� �̳��� �ű� �� ������ �ϴ� ������ ��������
��� �ð��� ���ؼ�(��� �ð��� �Ұ����ϴ� �̺�Ž�� ���) Ȯ���غ��� ����� ���� ���� ���������� �� �� �� �� ����..
search �Լ��� �����ܺ���
��.. �� �� ������ ������.. ó���� �賶������ �����ϰ� �ű⿡�� ������ �� Ǭ ū ������ �� ����. ���ʿ�
�� ������ ���ʴ�� �ذ��ϴ� ������ �ƴѵ� �� �賶������� ��������.. ��..*/

bool search(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid) {
	long long totG = 0;
	long long totS = 0;
	long long tot = 0;
	for (int i = 0; i < g.size(); i++) {
		long long time = t[i];
		long long roundT = time * 2;
		long long move = mid / roundT;
		if (mid % roundT >= time) move++;
		long long maxTake = w[i] * move;

		totG += min((long long)g[i], maxTake);
		totS += min((long long)s[i], maxTake);
		tot += min((long long)g[i] + s[i], maxTake);
	}
	if (totG >= a && totS >= b && tot >= a + b) return true;
	else return false;
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = -1;
	long long left = 0;
	long long right = 10e15;
	answer = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (search(a, b, g, s, w, t, mid)) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return answer;
}