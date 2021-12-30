#include <iostream>
#include <string>
using namespace std;

/*2021.12.30
스택으로 문제가 분류되어 있는데 실제로 stl 스택을 쓰면 풀 수 없다.
문제를 풀다가 느꼈지만 스택에서 top말고 다른 값을 볼 수 있어야하는데 
stl 스택으로는 그게 불가능하다. 그냥 간단하게 배열로 처리하면 될걸..
그리고 폭발 문자열을 스택에서 빼야한다고 생각했는데 굳이 빼지 않고
top 역할을 하는 idx까지 출력함으로써 해결한 것도 미처 생각하지 못했다.*/

char result[1000001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s, bomb;
	cin >> s >> bomb;
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		result[idx++] = s[i];
		int j = (int)bomb.size();
		if (s[i] == bomb[--j]) {
			bool chk = false;
			int size = idx - (int)bomb.length();
			for (int k = idx - 1; k >= size; k--) {
				if (result[k] == bomb[j--]) chk = true;
				else {
					chk = false;
					break;
				}
			}
			if (chk) idx -= bomb.size();
		}
	}
	if (idx == 0) cout << "FRULA";
	else {
		for (int i = 0; i < idx; i++)
			cout << result[i];
	}
}