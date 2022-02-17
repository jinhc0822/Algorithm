#include <vector>
#include <algorithm>
using namespace std;

/*2022.02.17
union find를 이용해볼까?*/

int solution(vector<int> stones, int k) {
	vector<pair<int, int>> s;
	vector<bool> stone(stones.size(), true);
	for (int i = 0; i < stones.size(); i++)
		s.push_back({ stones[i], i });
	sort(s.begin(), s.end());
}