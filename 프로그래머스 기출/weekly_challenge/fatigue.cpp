#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.02*/

int solution(int k, vector<vector<int>> dungeons) {
	int answer = 0;
	vector<int> d;
	for (int i = 0; i < dungeons.size(); i++)
		d.push_back(i);
	do {
		int cur = k, cnt = 0;
		for (int i = 0; i < d.size(); i++) {
			if (cur >= dungeons[d[i]][0]) {
				cur -= dungeons[d[i]][1];
				cnt++;
			}
			else break;
		}
		if (cnt > answer)
			answer = cnt;
	} while (next_permutation(d.begin(), d.end()));
	return answer;
}