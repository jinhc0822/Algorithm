#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.02
unordered_set 사용한 1줄 풀이가 있더라.*/

int solution(vector<int> nums) {
	int choose = nums.size() / 2;
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	if (choose >= nums.size())
		return nums.size();
	else
		return choose;
}