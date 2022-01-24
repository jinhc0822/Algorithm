#include <string>
#include <vector>
using namespace std;

/*2022.01.24
쉬움.*/

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<pair<int, int>> v;
	while (true) {
		v.clear();
		for (int i = 0; i < m - 1; i++)
			for (int j = 0; j < n - 1; j++)
				if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] &&
					board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
					v.push_back({ i, j });
		if (v.empty())
			break;
		for (auto p : v) {
			int y = p.first, x = p.second;
			board[y][x] = ' ';
			board[y + 1][x] = ' ';
			board[y][x + 1] = ' ';
			board[y + 1][x + 1] = ' ';
		}
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			bool chk = false;
			for (int j = m - 1; j >= 0; j--) {
				if (chk && board[j][i] != ' ') {
					board[j + cnt][i] = board[j][i];
					board[j][i] = ' ';
				}
				else if (board[j][i] == ' ') {
					cnt++;
					chk = true;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == ' ')
				answer++;
	return answer;
}