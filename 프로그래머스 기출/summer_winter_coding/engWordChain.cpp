#include <string>
#include <vector>
#include <map>
using namespace std;

/*2022.03.02*/

vector<int> solution(int n, vector<string> words) {
	map<string, bool> used;
	int turn = 1, idx = 0, cnt = 1;
	while (idx < words.size()) {
		if (idx != 0 && words[idx - 1].back() != words[idx][0])
			return { turn, cnt };
		if (used[words[idx]])
			return { turn, cnt };
		used[words[idx]] = true;
		turn++; idx++;
		if (turn > n) {
			turn = 1;
			cnt++;
		}
	}
	return { 0, 0 };
}