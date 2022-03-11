#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.11
처음에는 그냥 dfs로 풀려고 하다가 실패했고 다음에는 dp로 풀어야한다는 힌트를 얻고 dfs 푸는 방식 그대로
풀었다가 효율성에서 시간 초과를 받았다.. 결국 이번 idx에서 스티커를 뽑냐 안 뽑냐가 중요한거지
어떤 idx를 뽑을지는 사실 dp에서 고려해야할 사항이 아니다.. 근데 이 문제 재귀로 풀면 무조건 시간 초과 나오나보다..
근데 생각해보면 당연한 거 같기도.. 경우의 수는 항상 2가지 인데 3칸씩 띄워서 대충 선택하더라도 2^33333가지이다..
결국 답을 보았다..*/

int sz, dp[100000];

/*
// 풀이는 맞지만 시간초과가 걸린다.
int dfs(vector<int>& s, int idx) {
	if (idx >= sz) {
		return 0;
	}
	int& res = dp[idx];
	if (res != -1)
		return res;
	res = 0;
	res = max({ res, dfs(s, idx + 2), dfs(s, idx + 3) }) + s[idx];
	return res;
}*/
/*
// 두 번째 풀이인데 이건 왜 틀린지 잘 모르겠음..
int dfs(vector<int>& s, int idx, bool pick) {
	if (idx >= sz) {
		return 0;
	}
	int& res = dp[idx];
	if (res != -1)
		return res;
	res = 0;
	if (pick) res = dfs(s, idx + 1, false);
	else res = max({ dfs(s, idx + 1, true) + s[idx], dfs(s, idx + 1, false) });
	return res;
}*/
int solution(vector<int> sticker) {
	int answer = 0;
	sz = sticker.size();
	if (sz == 1)
		return sticker[0];
	dp[0] = sticker[0];
	dp[1] = sticker[0];
	for (int i = 2; i < sz - 1; i++)
		dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
	answer = max(answer, dp[sz - 2]);
	dp[0] = 0;
	dp[1] = sticker[1];
	for (int i = 2; i < sz; i++)
		dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
	answer = max(answer, dp[sz - 1]);
	return answer;
}