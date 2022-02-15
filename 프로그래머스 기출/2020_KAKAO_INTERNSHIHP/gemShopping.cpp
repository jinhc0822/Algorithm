#include <string>
#include <vector>
#include <map>
using namespace std;

/*2022.02.14
슬라이딩 윈도우 문제. 할만했음.*/

vector<int> solution(vector<string> gems) {
	map<string, int> jewels;
	int sz = 0;
	for (int i = 0; i < gems.size(); i++) {
		if (jewels[gems[i]] == 0)
			sz++;
		jewels[gems[i]]++;
	}
	jewels.clear();
	int start = 0, end = sz - 1;
	int typeNum = 0;
	for (int i = start; i <= end; i++) {
		if (jewels[gems[i]] == 0)
			typeNum++;
		else if (gems[start] == gems[i]) {
			start++;
			jewels[gems[i]]--;
		}
		jewels[gems[i]]++;
	}
	if (typeNum == sz)
		return { start + 1, end + 1 };
	vector<int> answer = { start, end, 100001 };
	while (true) {
		if (typeNum == sz) {
			while (jewels[gems[start]] != 1)
				jewels[gems[start++]]--;
			if (end-start+1<answer[2])
				answer = { start, end, end - start + 1 };
		}
		int next = end + 1;
		if (next == gems.size())
			break;
		if (jewels[gems[next]] == 0)
			typeNum++;
		else if (gems[start] == gems[next]) {
			start++;
			jewels[gems[next]]--;
		}
		jewels[gems[next]]++;
		end = next;
	}

	answer[0]++; answer[1]++;
	answer.pop_back();
	return answer;
}