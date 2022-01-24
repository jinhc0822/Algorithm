#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*2022.01.24
교집합을 이용해서 합집합의 수를 구했음. 어렵지는 않음.*/

string upper(string str) {
	for (int i = 0; i < str.size(); i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	return str;
}
void makeSet(string str, vector<string>& s) {
	for (int i = 0; i < str.size() - 1; i++) {
		if (!isalpha(str[i]))
			continue;
		if (!isalpha(str[i + 1])) {
			i++;
			continue;
		}
		s.push_back(str.substr(i, 2));
	}
}
int intersect(vector<string> s1, vector<string> s2) {
	int idx1 = 0, idx2 = 0, res = 0;
	while (idx1 < s1.size() && idx2 < s2.size()) {
		if (s1[idx1] == s2[idx2]) {
			res++;
			idx1++; idx2++;
		}
		else {
			if (s1[idx1] < s2[idx2])
				idx1++;
			else
				idx2++;
		}
	}
	return res;
}
int solution(string str1, string str2) {
	int answer = 0;
	vector<string> s1, s2;
	str1 = upper(str1);
	str2 = upper(str2);
	makeSet(str1, s1);
	makeSet(str2, s2);

	if (s1.empty() && s2.empty())
		return 65536;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (string s : s1)
		cout << s << ' ';
	cout << '\n';
	for (string s : s2)
		cout << s << ' ';
	double k = intersect(s1, s2);
	double u = (double)s1.size() + s2.size() - k;
	answer = (int)((k / u) * 65536);
	return answer;
}

int main() {
	cout << solution("aa1+aa2", "AAAA12");
}