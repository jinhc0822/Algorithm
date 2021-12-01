#include <iostream>
#include <cstring>
#include <string>
#define MOD 1000000
using namespace std;

/*2021.12.01
너무 헤맸다... 이런 문제는 반례를 찾아서 코딩을 하는게 제일 중요한데 
하나를 발견하면 다른 하나 빼먹는 실수가 많아서 조금 오래 걸렸다. 
이게 안 되면 이렇게 해볼까? 하는 방식 보다는 반례가 될 법한 예시들을
많이 생각해서 코딩할 때 계속계속 테스트 해주면서 해야할 것 같다.
그리고 재귀에서는 웬만하면 flag를 쓰지 말자. 더욱 헷갈린다.*/

string code;
int len, cache[5000];

int interpret(int idx) {
	if (idx == len) return 1;
	int& ret = cache[idx];
	if (ret != -1) return ret;
	ret = 0;
	if (code[idx] == '0') return 0;
	if (code[idx + 1] != '0') ret += interpret(idx + 1);
	if (idx < len - 1) {
		int tmp = stoi(code.substr(idx, 2));
		if (tmp >= 10 && tmp <= 26) ret += interpret(idx + 2);
		else if (tmp % 10 == 0) return 0;
	}
	return ret %= MOD;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> code;
	len = code.length();
	memset(cache, -1, sizeof(cache));
	cout << interpret(0);
}