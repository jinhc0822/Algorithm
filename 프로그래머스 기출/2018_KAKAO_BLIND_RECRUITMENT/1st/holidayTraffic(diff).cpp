#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.26
전에 백준에서 아주 유사한 문제를 풀어본 적이 있다. 하지만 다른 점이라고 하면
1초라는 시간 동안이라는 전제가 붙어 있고 주어지는 시간은 ms라서, 다른 흔한 문제에서는
구간은 겹치지 않지만 이 문제에서는 겹치는 경우가 있어서 헷갈렸었다.
그래서 잠깐 답을 봤는데 end 변수에 999를 더해준 것이 정말 중요한 포인트라고 할 수 있을 것 같다.
999를 더해줘서 그만큼 구간이 늘어나게 만드는 효과가 있는 것이다. 이 생각을 못했다..*/

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