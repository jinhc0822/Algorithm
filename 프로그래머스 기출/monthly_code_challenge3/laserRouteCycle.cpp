#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.01
¿ÏÀüÅ½»ö*/

vector<int> answer;
bool route[500][500][4];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int dDir[4][3] = { {0, 2, 3}, {1, 3, 2}, {2, 1, 0}, {3, 0, 1} };

void laserbeam(int y, int x, int dir, vector<string>& grid) {
	int len = 0;
	route[y][x][dir] = true;
	while (true) {
		y = y + dy[dir];
		if (y == grid.size())
			y = 0;
		else if (y < 0)
			y = grid.size() - 1;

		x = x + dx[dir];
		if (x == grid[0].size())
			x = 0;
		else if (x < 0)
			x = grid[0].size() - 1;

		if (grid[y][x] == 'S')
			dir = dDir[dir][0];
		else if (grid[y][x] == 'L')
			dir = dDir[dir][1];
		else
			dir = dDir[dir][2];
		if (route[y][x][dir])
			break;
		len++;
		route[y][x][dir] = true;
	}
	answer.push_back(len + 1);
}
vector<int> solution(vector<string> grid) {
	for (int i = 0; i < grid.size(); i++)
		for (int j = 0; j < grid[i].size(); j++)
			for (int k = 0; k < 4; k++)
				if (!route[i][j][k])
					laserbeam(i, j, k, grid);
	sort(answer.begin(), answer.end());
	return answer;
}