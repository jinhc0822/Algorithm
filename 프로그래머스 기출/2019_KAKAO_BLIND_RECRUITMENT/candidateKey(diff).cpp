#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.18*/

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int col = relation[0].size();
	int row = relation.size();
	int key[1 << 9] = { 0 };
	for (int i = 1; i <= col; i++) {
		vector<bool> tmp(col, true);
		for (int j = 0; j < i; j++)
			tmp[j] = false;
		do {
			vector<int> v;
			int res = 0;
			for (int i = 0; i < col; i++)
				if (tmp[i])
					v.push_back(i);
			for (int a : v)
				res |= (1 << a);
			for (int a : v) {
				int k = res &;
			}
		} while (next_permutation(tmp.begin(), tmp.end()));
	}
	return answer;
}