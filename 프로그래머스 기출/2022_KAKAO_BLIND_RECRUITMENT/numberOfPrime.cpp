#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

/*2022.02.03
2^19까지는 100만보다 작기 때문에 19자리수까지 나타낼 수 있는 long long을 써야한다.
채점에서 계속 오류 나서 뭔가 했네...*/

string kBase(int n, int k) {
	string res, tmp = "";
	while (n != 0) {
		tmp += (n % k + '0');
		n /= k;
	}
	for (int i = tmp.size() - 1; i >= 0; i--)
		res += tmp[i];
	return res;
}
bool isPrime(long long n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
int solution(int n, int k) {
	int answer = 0;
	string s = kBase(n, k);
	vector<string> v;
	stringstream ss(s);
	string t;
	while (getline(ss, t, '0'))
		v.push_back(t);
	for (string str : v) {
		if (str == "")
			continue;
		if (isPrime(stoll(str)))
			answer++;
	}
	return answer;
}