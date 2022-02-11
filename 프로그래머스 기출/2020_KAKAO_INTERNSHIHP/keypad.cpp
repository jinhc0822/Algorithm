#include <string>
#include <vector>
using namespace std;

/*2022.02.10
왤케 헤맸지ㅋㅋ;*/

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int arr[10] = { 4, 1, 1, 1, 2, 2, 2, 3, 3, 3 };
	pair<int, int> left = { 4, 1 }, right = { 4, 3 };
	for (int num : numbers) {	
		if (num % 3 == 1) {
			answer.push_back('L');
			left = { arr[num], 1 };
		}
		else if (num % 3 == 0 && num != 0) {
			answer.push_back('R');
			right = { arr[num], 3 };
		}
		else {
			pair<int, int> cur = { arr[num], 2 };
			int rDist = abs(cur.first - right.first) + abs(cur.second - right.second);
			int lDist = abs(cur.first - left.first) + abs(cur.second - left.second);
			if (rDist < lDist) {
				answer.push_back('R');
				right = cur;
			}
			else if (rDist > lDist) {
				answer.push_back('L');
				left = cur;
			}
			else {
				if (hand == "left") {
					answer.push_back('L');
					left = cur;
				}
				else {
					answer.push_back('R');
					right = cur;
				}
			}
		}
	}
	return answer;
}