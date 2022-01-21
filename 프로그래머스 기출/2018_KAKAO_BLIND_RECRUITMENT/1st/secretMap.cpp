#include <string>
#include <vector>
using namespace std;

/*2022.01.21
쉬움.*/

string toBinary(int num, int n) {
	string ans = "";
	while (num != 0) {
		char c = (num % 2 == 1) ? '#' : ' ';
		ans = c + ans;
		num /= 2;
	}
	while (ans.size() < n)
		ans = ' ' + ans;
	return ans;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		int k = arr1[i] | arr2[i];
		answer.push_back(toBinary(k, n));
	}
	return answer;
}