#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

/*2022.03.10
머리로는 어떻게 구현할지 감이 오지만 막상 코드를 짜려고 하면 막히는 부분이 많았던 문제.
결국 답을 참고하긴 했다. dfs나 bfs를 통해서 어떤 모양의 도형이 있는 파악하는 부분은
같지만, 위치가 달라서 좌표를 비교하는 것은 힘들다고 생각했는데 이 분은 한쪽으로 도형을
몰아넣어 이 문제를 해결했다. 이 생각을 못해서 풀지 못한 것 같다.
그리고 회전 행렬을 사용해서 회전한 도형과 비교하는 방법을 사용했다. 생각치도 못한 방법..*/

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int chk[51][51];

vector<pii> bfs(vector<vector<int>>& input, int x, int y, int target) {
	queue<pii> q;
	vector<pii> res;
	q.push({ x, y });
	res.push_back({ x, y });
	chk[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < input.size() && ny >= 0 && ny < input.size()) {
				if (!chk[nx][ny] && input[nx][ny] == target) {
					chk[nx][ny] = true;
					q.push({ nx, ny });
					res.push_back({ nx, ny });
				}
			}
		}
	}
	return res;
}
vector<vector<pii>> convert(vector<vector<pii>>& before, int value) {
	vector<vector<pii>> after;
	for (auto k : before) {
		int xMin = value, yMin = value;
		vector<pii> tmp;
		for (auto i : k) {
			xMin = min(xMin, i.first);
			yMin = min(yMin, i.second);
		}
		for (auto i : k)
			tmp.push_back({ i.first - xMin, i.second - yMin });
		after.push_back(tmp);
	}
	return after;
}
vector<pii> rotation(vector<pii>& input) {
	vector<pii> res;
	for (auto i : input) {
		int afterX = -i.second;
		int afterY = i.first;
		res.push_back({ afterX, afterY });
	}
	return res;
}
bool comp(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	int inputSize = game_board.size();

	vector<vector<pii>> blanks;
	for (int i = 0; i < inputSize; i++)
		for (int j = 0; j < inputSize; j++)
			if (game_board[i][j] == 0 && !chk[i][j])
				blanks.push_back(bfs(game_board, i, j, 0));

	for (int i = 0; i < inputSize; i++)
		for (int j = 0; j < inputSize; j++)
			chk[i][j] = false;

	vector<vector<pii>> shapes;
	for (int i = 0; i < inputSize; i++)
		for (int j = 0; j < inputSize; j++)
			if (table[i][j] == 1 && !chk[i][j])
				shapes.push_back(bfs(table, i, j, 1));

	vector<vector<pii>> afterBlanks = convert(blanks, 100);
	for (int i = 0; i < afterBlanks.size(); i++)
		sort(afterBlanks[i].begin(), afterBlanks[i].end());

	vector<vector<pii>> afterShapes = convert(shapes, 100);

	vector<vector<vector<pii>>> finalShapes;
	for (auto k : afterShapes) {
		vector<vector<pii>> afterTmp;
		for (int i = 0; i < 4; i++) {
			vector<pii> tmp = rotation(k);
			afterTmp.push_back(tmp);
			k = tmp;
		}
		vector<vector<pii>> afterRotation = convert(afterTmp, 0);
		for (int i = 0; i < afterRotation.size(); i++)
			sort(afterRotation[i].begin(), afterRotation[i].end(), comp);
		finalShapes.push_back(afterRotation);
	}

	int tableChk[2501] = { false, };

	for (int i = 0; i < afterBlanks.size(); i++) {
		vector<pii> blank = afterBlanks[i];
		bool shapeFlag = false;
		for (int j = 0; j < finalShapes.size(); j++) {
			if (tableChk[j])
				continue;
			vector<vector<pii>> fourShapes = finalShapes[j];
			if (blank.size() != fourShapes[0].size())
				continue;
			for (auto shapes : fourShapes) {
				int oneFlag = true;
				for (int k = 0; k < blank.size(); k++) {
					pii bl = blank[k];
					pii sh = shapes[k];
					if (bl.first == sh.first && bl.second == sh.second)
						continue;
					else {
						oneFlag = false;
						break;
					}
				}
				if (oneFlag) {
					shapeFlag = true;
					answer += blank.size();
					break;
				}
			}
			if (shapeFlag) {
				tableChk[j] = true;
				break;
			}
		}
	}
	return answer;
}