#include <vector>
#include <algorithm>
#define SIZE 11
using namespace std;

/*2022.02.04
그렇게 어렵지 않은 문제였는데 이상하게 헤매서 답을 봤다. 
딱 보자마자 완전탐색이라는 생각이 들었는데 dfs로 푸는 감이 안 와서
(아마 백트래킹을 쓴지 너무 오래돼서 그런듯..) 
조합을 이용해서 전부 다 구해서 풀기 하다가 이건 진짜 아닌가 같아서 답지봄..*/

int maxDiff;
vector<int> answer(1, -1), ryan, apeach;

bool comp() {
	for (int i = SIZE - 1; i >= 0; i--) {
		if (ryan[i] > answer[i]) return true;
		else if (ryan[i] < answer[i]) return false;
	}
}
void calc() {
	int ryanScore = 0, apeachScore = 0;
	for (int i = 0; i < SIZE; i++) {
		if (ryan[i] > apeach[i])
			ryanScore += SIZE - 1 - i;
		else if (apeach[i] > 0)
			apeachScore += SIZE - 1 - i;
	}
	int diff = ryanScore - apeachScore;
	if (diff > 0 && diff >= maxDiff) {
		if (maxDiff == diff && !comp())
			return;
		maxDiff = diff;
		answer = ryan;
	}
}
void dfs(int idx, int arrows) {
	if (idx == 11 || arrows == 0) {
		ryan[10] += arrows;
		calc();
		ryan[10] -= arrows;
		return;
	}
	if (apeach[idx] < arrows) {
		ryan[idx] += apeach[idx] + 1;
		dfs(idx + 1, arrows - apeach[idx] - 1);
		ryan[idx] -= apeach[idx] + 1;
	}
	dfs(idx + 1, arrows);
}
vector<int> solution(int n, vector<int> info) {
	ryan.resize(SIZE);
	apeach = info;
	dfs(0, n);
	return answer;
}