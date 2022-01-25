#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.01.25
쉬움.*/

struct File {
	string head;
	int num;
	int idx;
};

bool comp(File a, File b) {
	if (a.head != b.head)
		return a.head < b.head;
	else {
		if (a.num != b.num)
			return a.num < b.num;
		else
			return a.idx < b.idx;
	}
}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<File> v;
	for (int i = 0; i < files.size(); i++) {
		string s = files[i];
		for (int j = 0; j < s.size(); j++)
			s[j] = toupper(s[j]);
		int k = 0, m = s.size();
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				k = j;
				break;
			}
		}
		string h = s.substr(0, k);
		for (int j = k; j < s.size(); j++) {
			if (!(s[j] >= '0' && s[j] <= '9')) {
				m = j;
				break;
			}
		}
		int n = stoi(s.substr(k, m - k));
		v.push_back({ h, n, i });
		sort(v.begin(), v.end(), comp);
	}
	for (File f : v)
		answer.push_back(files[f.idx]);
	return answer;
}