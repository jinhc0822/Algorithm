#include <vector>
using namespace std;

/*2022.01.11
그냥 문제에서 주어진대로 하면 그렇게 어렵진 않은 문제. 함수들의 인자를 v로 하지 말고 구조체를 사용하고 enum을 사용하거나
define을 사용해서 보나 기둥을 좀 더 명확하게 드러내줄 수 있는 변수명을 썼더라면 좀 더 빨리 풀지 않았을까..*/

int N;
bool build[101][101][2];

bool canPillar(vector<int> v) {
	if (v[1] == 0)
		return true;
	if (build[v[0]][v[1]][1])
		return true;
	if (v[1] - 1 >= 0) {
		if (build[v[0]][v[1] - 1][0])
			return true;
	}
	if (v[0] - 1 >= 0) {
		if (build[v[0] - 1][v[1]][1])
			return true;
	}
	return false;
}
bool canBo(vector<int> v) {
	if (v[1] - 1 >= 0) {
		if (build[v[0]][v[1] - 1][0])
			return true;
		else if (v[0] + 1 <= N)
			if (build[v[0] + 1][v[1] - 1][0])
				return true;
	}
	if (v[0] - 1 >= 0 && v[0] + 1 <= N) {
		if (build[v[0] - 1][v[1]][1] && build[v[0] + 1][v[1]][1])
			return true;
	}
	return false;
}
bool can(vector<int> v) {
	//설치인 경우
	if (v[3] == 1) {
		// 기둥일 경우
		if (v[2] == 0)
			return canPillar({ v[0], v[1] });
		// 보인 경우
		else
			return canBo({ v[0], v[1] });
	}
	// 삭제인 경우
	else {
		// 기둥일 경우
		if (v[2] == 0) {
			build[v[0]][v[1]][0] = false;
			if (v[0] - 1 >= 0) {
				if (build[v[0] - 1][v[1] + 1][1])
					if (!canBo({ v[0] - 1, v[1] + 1 })) {
						build[v[0]][v[1]][0] = true;
						return false;
					}

			}
			if (v[1] + 2 <= N) {
				if (build[v[0]][v[1] + 1][0])
					if (!canPillar({ v[0], v[1] + 1 })) {
						build[v[0]][v[1]][0] = true;
						return false;
					}
			}
			if (build[v[0]][v[1] + 1][1]) {
				if (!canBo({ v[0], v[1] + 1 })) {
					build[v[0]][v[1]][0] = true;
					return false;
				}
			}
			build[v[0]][v[1]][0] = true;
			return true;
		}
		// 보인 경우
		else {
			build[v[0]][v[1]][1] = false;
			if (v[0] - 1 >= 0) {
				if (build[v[0] - 1][v[1]][1])
					if (!canBo({ v[0] - 1, v[1] })) {
						build[v[0]][v[1]][1] = true;
						return false;
					}
			}
			if (build[v[0]][v[1]][0]) {
				if (!canPillar({ v[0], v[1] })) {
					build[v[0]][v[1]][1] = true;
					return false;
				}
			}
			if (v[0] + 1 <= N) {
				if (build[v[0] + 1][v[1]][0])
					if (!canPillar({ v[0] + 1, v[1] })) {
						build[v[0]][v[1]][1] = true;
						return false;
					}
			}
			if (v[0] + 2 <= N) {
				if (build[v[0] + 1][v[1]][1])
					if (!canBo({ v[0] + 1, v[1] })) {
						build[v[0]][v[1]][1] = true;
						return false;
					}
			}
			build[v[0]][v[1]][1] = true;
			return true;
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;
	for (int i = 0; i < build_frame.size(); i++) {
		vector<int> v = build_frame[i];
		if (can(v)) {
			if (v[3] == 1)
				build[v[0]][v[1]][v[2]] = true;
			else
				build[v[0]][v[1]][v[2]] = false;
		}
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k < 2; k++)
				if (build[i][j][k])
					answer.push_back({ i, j, k });
	return answer;
}