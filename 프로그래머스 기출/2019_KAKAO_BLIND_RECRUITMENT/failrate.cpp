#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.13
문제를 잘 읽자.. 문제는 매우 쉬움.*/

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
	for (int k : stages)
		for (int i = 1; i < k; i++)
			s[i]++;
	rate[0].first = -1;
	for (int i = 1; i <= N; i++) {
		if (sz > 0)
			rate[i].first = (sz - s[i]) / (double)sz;
		else
			rate[i].first = 0;
		rate[i].second = i;
		sz -= sz - s[i];
	}
	sort(rate.begin(), rate.end(), comp);
	for (int i = 0; i < rate.size() - 1; i++)
		answer.push_back(rate[i].second);
	return answer;
}