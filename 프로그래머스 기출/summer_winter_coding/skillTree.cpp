#include <vector>
#include <string>
using namespace std;

/*2022.03.02*/

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	char pre[26] = { 0, };
	for (int i = 1; i < skill.size(); i++)
		pre[skill[i] - 'A'] = skill[i - 1];
	for (int i = 0; i < skill_trees.size(); i++) {
		bool chk[26] = { false, }, b = true;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (pre[skill_trees[i][j] - 'A'] != 0)
				if (!chk[pre[skill_trees[i][j] - 'A'] - 'A']) {
					b = false;
					break;
				}	
			chk[skill_trees[i][j] - 'A'] = true;
		}
		if (b)
			answer++;
	}
	return answer;
}