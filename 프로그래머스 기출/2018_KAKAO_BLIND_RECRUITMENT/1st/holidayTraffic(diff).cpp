#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.26
���� ���ؿ��� ���� ������ ������ Ǯ� ���� �ִ�. ������ �ٸ� ���̶�� �ϸ�
1�ʶ�� �ð� �����̶�� ������ �پ� �ְ� �־����� �ð��� ms��, �ٸ� ���� ����������
������ ��ġ�� ������ �� ���������� ��ġ�� ��찡 �־ �򰥷Ⱦ���.
�׷��� ��� ���� �ôµ� end ������ 999�� ������ ���� ���� �߿��� ����Ʈ��� �� �� ���� �� ����.
999�� �����༭ �׸�ŭ ������ �þ�� ����� ȿ���� �ִ� ���̴�. �� ������ ���ߴ�..*/

bool comp(pair<int, bool> a, pair<int, bool> b) {
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second > b.second;
}
int solution(vector<string> lines) {
	int answer = 0;
	vector<pair<int, bool>> t;
	for (int i = 0; i < lines.size(); i++) {
		int h = stoi(lines[i].substr(11, 2));
		int m = stoi(lines[i].substr(14, 2));
		int s = stoi(lines[i].substr(17, 2));
		int ms = stoi(lines[i].substr(20, 3));
		int idx = 24;
		string res = "";
		while (lines[i][idx] != 's') {
			if (lines[i][idx] == '.') {
				idx++;
				continue;
			}
			res += lines[i][idx++];
		}
		while (res.size() != 4)
			res += '0';
		int responseTime = stoi(res);
		h = h * 60 * 60 * 1000;
		m = m * 60 * 1000;
		s = s * 1000;
		int start = h + m + s + ms - responseTime + 1;
		int end = h + m + s + ms + 999;
		t.push_back({ start, true });
		t.push_back({ end, false });
	}
	sort(t.begin(), t.end(), comp);
	int traffic = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i].second)
			traffic++;
		else
			traffic--;
		if (answer < traffic) answer = traffic;
	}
	return answer;
}