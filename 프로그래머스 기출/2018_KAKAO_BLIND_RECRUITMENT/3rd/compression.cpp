#include <string>
#include <vector>
#include <map>
using namespace std;

/*2022.01.25
쉬움.*/

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> m;
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++)
		m.insert({ alpha.substr(i, 1), i + 1 });
	int idx = 27, cnt = 1;
	for (int i = 0; i < msg.size(); ) {
		cnt = 1;
		while (true) {
			if (m[msg.substr(i, cnt)] == 0 || i + cnt > msg.size()) {
				cnt--;
				break;
			}
			cnt++;
		}
		answer.push_back(m[msg.substr(i, cnt)]);
		m[msg.substr(i, cnt + 1)] = idx++;
		i += cnt;
	}
	return answer;
}