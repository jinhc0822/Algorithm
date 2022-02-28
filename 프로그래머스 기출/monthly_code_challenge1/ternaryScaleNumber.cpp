#include <string>
using namespace std;

/*2022.02.28*/

string tri(int n) {
	string s = "";
	while (n != 0) {
		s += (n % 3 + '0');
		n /= 3;
	}
	return s;
}
int solution(int n) {
	int answer = 0;
	string s = tri(n);
	for (int i = s.size() - 1, k = 1; i >= 0; i--, k *= 3)
		answer += (s[i] - '0') * k;
	return answer;
}