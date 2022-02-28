#include <vector>
using namespace std;

/*2022.02.28
백준에 똑같은 문제가 있는 것 같다.*/

int cnt[2];

void quad(int y, int x, int sz, vector<vector<int>>& arr) {
	int k = arr[y][x];
	if (sz == 1) {
		cnt[k]++;
		return;
	}
	bool chk = true;
	for (int i = y; i < y + sz; i++) {
		for (int j = x; j < x + sz; j++) {
			if (arr[i][j] != k) {
				chk = false;
				break;
			}
		}
	}
	if (chk) {
		cnt[k]++;
		return;
	}
	else {
		int s = sz / 2;
		quad(y, x, s, arr);
		quad(y, x + s, s, arr);
		quad(y + s, x, s, arr);
		quad(y + s, x + s, s, arr);
	}
}
vector<int> solution(vector<vector<int>> arr) {
	quad(0, 0, arr.size(), arr);
	return { cnt[0], cnt[1] };
}