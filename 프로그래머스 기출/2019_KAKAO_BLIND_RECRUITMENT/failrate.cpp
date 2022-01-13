#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.13*/

bool comp(pair<double, int> a, pair<double, int> b) {
	if (a.first != b.first)
		return a.first > b.first;
	else
		return a.second < b.second;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> s(N + 1);
	vector<pair<double, int>> rate(N + 1);
	int sz = stages.size();
	for (int k : stages) {
		if (k > N) k = N;
		for (int i = 1; i <= k; i++)
			s[i]++;
	}
	rate[0].first = -1;
	for (int i = 1; i <= N; i++) {
		rate[i].first = (N - s[i]) / sz;
		rate[i].second = i;
		sz -= N - s[i];
	}
	sort(rate.begin(), rate.end());
	for (int i = 0; i < rate.size() - 1; i++)
		answer.push_back(rate[i].second);
	return answer;
}