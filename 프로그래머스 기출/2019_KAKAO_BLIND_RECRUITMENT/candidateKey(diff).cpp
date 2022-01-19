#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.18
완전탐색 문제였다. 조합을 구현하여 어떤 col들을 비교할지 정해주었고
유일성을 구현하기 위해 일일히 그 값들을 비교하는 방법을 썼다. 그리고 최소성을 구현하기 위해 key라는 배열과 비트마스킹을 사용했다.
여기서도 r=relation을 빼먹고 comp 안에서 i의 값이 row-1까지 가는 실수와 key[k]가 0이 아닐때 key[res] 값을 변경해야하는데 key[k]을 변경하는 실수가 있었다.
실수를 줄여야 할 것 같은데... 이런 사소한 것들이 모여서 시간을 너무 많이 잡아먹는다.*/

vector<vector<string>> r;
int row, col;

bool comp(vector<int>& v) {
	for (int i = 0; i < row - 1; i++) {
		for (int j = i + 1; j < row; j++) {
			bool chk = true;
			for (int k = 0; k < v.size(); k++) {
				if (r[i][v[k]] != r[j][v[k]]) {
					chk = false;
					break;
				}
			}
			if (chk)
				return false;
		}
	}
	return true;
}
int solution(vector<vector<string>> relation) {
	int answer = 0;
	col = relation[0].size();
	row = relation.size();
	r = relation;
	int key[1 << 8] = { 0 };
	for (int i = col - 1; i >= 0; i--) {
		vector<bool> tmp(col, true);
		for (int j = 0; j < i; j++)
			tmp[j] = false;
		do {
			vector<int> v;
			int res = 0;
			for (int j = 0; j < col; j++)
				if (tmp[j])
					v.push_back(j);
			for (int a : v)
				res |= (1 << a);
			bool chk = true;
			for (int a : v) {
				int k = res - (1 << a);
				if (key[k] == -1 || key[k] == 1) {
					key[res] = -1;
					chk = false;
				}
			}
			if (!chk) continue;
			if (comp(v)) {
				answer++;
				key[res] = 1;
			}
		} while (next_permutation(tmp.begin(), tmp.end()));
	}
	return answer;
}