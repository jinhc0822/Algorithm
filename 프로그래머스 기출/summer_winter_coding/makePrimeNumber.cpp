#include <vector>
using namespace std;

/*2022.03.01*/

int solution(vector<int> nums) {
	int answer = 0;
	vector<bool> prime(3001, true);
	for (int i = 2; i < 3001; i++) {
		if (!prime[i])
			continue;
		for (int j = i * 2; j < 3001; j += i)
			prime[j] = false;
	}
	for (int i = 0; i < nums.size() - 2; i++)
		for (int j = i + 1; j < nums.size() - 1; j++)
			for (int k = j + 1; k < nums.size(); k++)
				if (prime[nums[i] + nums[j] + nums[k]])
					answer++;
					
	return answer;
}