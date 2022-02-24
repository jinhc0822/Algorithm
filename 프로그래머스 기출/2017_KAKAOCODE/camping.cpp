#include <vector>
#include <algorithm>
using namespace std;

/*2022.02.23
아니 솔직히 너무 싱거운데.. 당연히 시간초과지 않을까 생각했던 코드가 맞네;;*/

int solution(int n, vector<vector<int>> data) {
	int answer = 0;
	sort(data.begin(), data.end());
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[i][0] == data[j][0] || data[i][1] == data[j][1])
				continue;
			int my = min(data[i][1], data[j][1]);
			int My = max(data[i][1], data[j][1]);
			bool chk = false;
			for (int k = i + 1; k < j; k++) {
				if ((data[k][0] > data[i][0] && data[k][0] < data[j][0]) &&
					(data[k][1] > my&& data[k][1] < My)) {
					chk = true;
					break;
				}
			}
			if (chk)
				continue;
			answer++;
		}
	}
	return answer;
}