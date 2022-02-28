#include <vector>
#include <algorithm>
using namespace std;

/*2022.02.28
그냥 구현했는데 다른 풀이 보니까 규칙이 있긴 한거 같더라..*/

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
		arr[i].assign(i + 1, 0);
	int cy = 0, cx = 0, num = 1;
	while (true) {
		while (true) {
			if (cy >= n || arr[cy][cx] != 0) {
				cy--;
				break;
			}
			arr[cy++][cx] = num++;
		}
		if (arr[cy][++cx] != 0)
			break;
		while (true) {
			if (cx > cy || arr[cy][cx] != 0) {
				cx--;
				break;
			}
			arr[cy][cx++] = num++;
		}
		if (arr[--cy][--cx] != 0)
			break;
		while (true) {
			if (arr[cy][cx] != 0) {
				cy++;
				cx++;
				break;
			}
			arr[cy--][cx--] = num++;
		}
		if (arr[++cy][cx] != 0)
			break;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < arr[i].size(); j++)
			answer.push_back(arr[i][j]);
	return answer;
}