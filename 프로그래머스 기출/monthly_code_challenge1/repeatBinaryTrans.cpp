#include <string>
#include <vector>
using namespace std;

/*2022.02.28*/

int cnt, zero;

string trans(string s) {
	cnt++;
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') k++;
		else zero++;
	}
	string tmp = "", res = "";
	while (k != 0) {
		tmp += (k % 2) + '0';
		k /= 2;
	}
	for (int i = tmp.size() - 1; i >= 0; i--)
		res += tmp[i];
	return res;
}
vector<int> solution(string s) {
	while (s != "1") {
		s = trans(s);
	}
	return { cnt, zero };
}