#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

/*2022.02.24
할만함.*/

int solution(int n, vector<string> data) {
	int answer = 0;
	char kakaoFriends[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	do {
		map<char, int> idx;
		for (int i = 0; i < 8; i++)
			idx[kakaoFriends[i]] = i;
		bool chk = true;
		for (int i = 0; i < n; i++) {
			string s = data[i];
			int p = idx[s[0]];
			int q = idx[s[2]];
			int dist = abs(p - q) - 1;
			if (s[3] == '=') {
				if (dist != s[4] - '0') {
					chk = false;
					break;
				}
			}
			else if (s[3] == '>') {
				if (dist <= s[4] - '0') {
					chk = false;
					break;
				}
			}
			else {
				if (dist >= s[4] - '0') {
					chk = false;
					break;
				}
			}
		}
		if (chk)
			answer++;
	} while (next_permutation(kakaoFriends, kakaoFriends + 8));
	return answer;
}