#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*2022.02.17
union find를 이용해볼까?*/

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
		for (int i = 0; i < stones.size(); i++)
			cout << parent[stones[i]] << ' ';
		cout << '\n';
		if (connected[find(cur.second)] >= k)
			return cur.first;
		idx++;
	}
}

int main() {
	cout << solution({ 10, 10, 3, 2, 3, 3, 2, 3, 10, 10 }, 5);
}