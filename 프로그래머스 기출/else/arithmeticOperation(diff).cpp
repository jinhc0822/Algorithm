#include <vector>
#include <string>
#include <algorithm>
#define INF 1000000000
using namespace std;

/*2022.03.16
역시 dp는 어렵구먼.. 항상 이런 문제를 보면 재귀로 해결하려는 습관이 헤매게 되는 원인이 된다..*/

int dpMax[101][101];
int dpMin[101][101];

int solution(vector<string> arr) {
	int sz = arr.size() / 2 + 1;
	for (int i = 0; i < arr.size(); i += 2) {
		dpMax[i / 2][i / 2] = stoi(arr[i]);
		dpMin[i / 2][i / 2] = stoi(arr[i]);
	}
	for (int len = 1; len < sz; len++) {
		for (int i = 0; i + len < sz; i++) {
			int j = i + len;
			dpMax[i][j] = -INF;
			dpMin[i][j] = INF;
			for (int k = 0; i + k < j; k++) {
				if (arr[(i + k) * 2 + 1] == "-") {
					dpMax[i][j] = max(dpMax[i][j], dpMax[i][i + k] - dpMin[i + k + 1][j]);
					dpMin[i][j] = min(dpMin[i][j], dpMin[i][i + k] - dpMax[i + k + 1][j]);
				}
				else {
					dpMax[i][j] = max(dpMax[i][j], dpMax[i][i + k] + dpMax[i + k + 1][j]);
					dpMin[i][j] = min(dpMin[i][j], dpMin[i][i + k] + dpMin[i + k + 1][j]);
				}
			}
		}
	}
	return dpMax[0][sz - 1];
}