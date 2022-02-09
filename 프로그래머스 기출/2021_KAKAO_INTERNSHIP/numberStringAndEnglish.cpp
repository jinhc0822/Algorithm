#include <string>
using namespace std;

/*2022.02.09
쉬움.*/

int solution(string s) {
	string answer = "";
	pair<string, int> num[10];
	num[0] = { "ze", 4 };
	num[1] = { "on", 3 };
	num[2] = { "tw", 3 };
	num[3] = { "th", 5 };
	num[4] = { "fo", 4 };
	num[5] = { "fi", 4 };
	num[6] = { "si", 3 };
	num[7] = { "se", 5 };
	num[8] = { "ei", 5 };
	num[9] = { "ni", 4 };
	for (int i = 0; i < s.size();) {
		if (s[i] >= '0' && s[i] <= '9') {
			answer += s[i];
			i++;
		}
		else {
			for (int j = 0; j < 10; j++) {
				if (s.substr(i, 2) == num[j].first) {
					answer += (j + '0');
					i += num[j].second;
					break;
				}
			}
		}
	}
	return stoi(answer);
}