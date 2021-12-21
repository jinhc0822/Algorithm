#include <iostream>
using namespace std;

/*2021.12.21
인터넷의 코드를 그대로 가져왔다. 실수로 메모를 확인해버리는 바람에 생각할 겨를도 없이 
스포를 당해버렸다. 그래도 쉬운 문제는 아닌 것 같다.
경우의 수를 잘 나눠야한다. 그 중 가장 중요한 포인트는 만약 멀티탭이 꽉찬 상태에서
멀티탭에 없는 기기를 꼳아야하는 경우 가장 나중에 다시 사용되거나 이제 사용할 일이 없는
기기를 찾는 것이다. 이것을 구현한 코드가 상당히 좀 독특하다. 다시 풀어볼만한 문제.*/

int n, k;
int schedule[101], plug[101];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> schedule[i];
	int ans = 0;
	for (int i = 0; i < k; i++) {
		bool pluggedIn = false;
		// 이미 멀티탭에 꼳혀있는 경우
		for (int j = 0; j < n; j++)
			if (plug[j] == schedule[i]) {
				pluggedIn = true;
				break;
			}
		if (pluggedIn) continue;
		// 멀티탭에 비어있을 칸이 있을 경우
		for (int j = 0; j < n; j++)
			if (!plug[j]) {
				plug[j] = schedule[i];
				pluggedIn = true;
				break;
			}
		if (pluggedIn) continue;
		// 가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾기
		int idx, deviceIdx = -1;
		for (int j = 0; j < n; j++) {
			int lastIdx = 0;
			for (int r = i + 1; r < k; r++) {
				if (plug[j] == schedule[r]) break;
				lastIdx++;
			}
			if (lastIdx > deviceIdx) {
				idx = j;
				deviceIdx = lastIdx;
			}
		}
		ans++;
		plug[idx] = schedule[i];
	}
	cout << ans;
}