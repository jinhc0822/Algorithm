#include <vector>
#include <queue>
using namespace std;

/*2022.02.17
union find를 이용했는데 25점이 나왔다. 어느 부분에서 틀린걸까?..
인원수를 이분탐색으로 조절해서 푸는 방법도 있다. 난 다른 방법을 봤다.
너무 하드하게 코딩하려고 한 것 같다. 이분탐색 풀이처럼 인원수 중점으로 생각하든가
아님 이 풀이처럼 구간에 집중하던가 했었어야하는데 순서대로 직접 해보다가
어디선가 틀린것 같다.
+효율성 테스트가 있을 경우에는 구현을 요구하기 보다는 특정한 알고리즘이나 자료구조를
묻는 것이기 때문에 알고있는 탐색 방법 중 올바른 탐색방법을 찾는 것이 푸는 데에 도움이
될 것 같다.*/

int solution(vector<int> stones, int k) {
	int answer = 987654321;
	deque<pair<int, int>> dq;
	for (int i = 0; i < stones.size(); i++) {
		while (!dq.empty() && dq.front().second < i - k + 1)
			dq.pop_front();
		while (!dq.empty() && dq.back().first < stones[i])
			dq.pop_back();
		dq.push_back(make_pair(stones[i], i));
		if (i >= k - 1 && dq.front().first < answer) answer = dq.front().first;
	}
	return answer;
}

/*
int parent[200001];
int connected[200001];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	parent[u] = v;
	connected[u]++;
	connected[v]++;
}
int solution(vector<int> stones, int k) {
	vector<pair<int, int>> s;
	vector<bool> stone(stones.size(), true);
	for (int i = 0; i < stones.size(); i++)
		s.push_back({ stones[i], i });
	sort(s.begin(), s.end());
	for (int i = 0; i < stones.size(); i++) {
		parent[i] = i;
		connected[i] = 1;
	}
	int idx = 0;
	while (true) {
		if (idx == s.size())
			break;
		pair<int, int> cur = s[idx];
		stone[cur.second] = false;
		if (cur.second != 0 && stone[cur.second - 1] == false)
			merge(cur.second, cur.second - 1);
		if (cur.second != s.size() - 1 && stone[cur.second + 1] == false)
			merge(cur.second, cur.second + 1);
		if (connected[parent[cur.second]] >= k)
			return cur.first;
		idx++;
	}
}*/