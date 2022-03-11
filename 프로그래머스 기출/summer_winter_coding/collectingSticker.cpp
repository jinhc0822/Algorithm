#include <vector>
using namespace std;

/*2022.03.11*/

int answer = 0, sz;

void dfs(vector<int>& s, int idx, int sum, bool chk) {
	if (idx==sz) {
		if (answer < sum)
			answer = sum;
		return;
	}
	dfs(s, idx + 2, sum + s[idx + 2], chk);
	dfs(s, idx + 3, sum + s[idx + 3], chk);
}
int solution(vector<int> sticker) {
	sz = sticker.size();
	if (sz == 1)
		return sticker[0];
	if (sz % 2 == 0) {
		dfs(sticker, 0, sticker[0], true);
		dfs(sticker, 1, sticker[1], false);
	}
	else {
		dfs(sticker, 0, sticker[0], false);
		dfs(sticker, 1, sticker[1], false);
		dfs(sticker, 2, sticker[2], false);
	}
	return answer;
}