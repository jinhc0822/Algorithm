#include <vector>
using namespace std;

/*2022.02.04
진작에 이 문제는 단순하게 풀면 안된다는 것을 알고 있었고 머리를 한 시간 동안
굴려보았지만 해결방법을 찾지 못했음. 진짜 벽느낌..ㅜ
이 문제를 누적합으로 풀어야한다는 것을 알고 참 당황스러웠다. 누적합을 이런 방식으로
사용할 줄이야. 뭐라 할 말이 없네..*/

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int n = board.size(), m = board[0].size();
	vector<vector<int>> sum(n);
	for (int i = 0; i < n; i++)
		sum[i].resize(m, 0);
	for (int i = 0; i < skill.size(); i++) {
		vector<int> v = skill[i];
		int k = (v[0] == 1) ? -v[5] : v[5];
		sum[v[1]][v[2]] += k;
		if (v[3] + 1 < n)
			sum[v[3] + 1][v[2]] += -k;
		if (v[4] + 1 < m)
			sum[v[1]][v[4] + 1] += -k;
		if (v[3] + 1 < n && v[4] + 1 < m)
			sum[v[3] + 1][v[4] + 1] += k;
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++)
			sum[i][j] = sum[i][j - 1] + sum[i][j];

	for (int j = 0; j < m; j++)
		for (int i = 1; i < n; i++)
			sum[i][j] = sum[i - 1][j] + sum[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board[i][j] += sum[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] > 0)
				answer++;
	return answer;
}