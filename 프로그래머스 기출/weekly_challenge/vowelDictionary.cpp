#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.02
문제가 간단할수록 풀이는 다양하다..*/

vector<string> v;

void dfs(int cnt, string cur, string s){
	if (cnt == 5)
		return;
	for (int i = 0; i < 5; i++) {
		v.push_back(cur + s[i]);
		dfs(cnt + 1, cur + s[i], s);
	}
}
int solution(string word) {
	dfs(0, "", "AEIOU");
	sort(v.begin(), v.end());
	auto it = find(v.begin(), v.end(), word);
	return it - v.begin() + 1;
}