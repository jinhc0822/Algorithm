#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*2022.01.18
stringstream 이용해서 풀기. 어려운 문제는 아니었다.*/

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	for (string s : record) {
		string t;
		stringstream ss(s);
		vector<string> v;
		while (getline(ss, t, ' ')) {
			v.push_back(t);
		}
		if (v[0] == "Enter")
			m[v[1]] = v[2];
		else if (v[0] == "Change")
			m[v[1]] = v[2];
	}
	for (string s : record) {
		string t;
		stringstream ss(s);
		vector<string> v;
		while (getline(ss, t, ' ')) {
			v.push_back(t);
		}
		if (v[0] == "Enter")
			answer.push_back(m[v[1]] + "님이 들어왔습니다.");
		else if (v[0] == "Leave")
			answer.push_back(m[v[1]] + "님이 나갔습니다.");
	}
	return answer;
}