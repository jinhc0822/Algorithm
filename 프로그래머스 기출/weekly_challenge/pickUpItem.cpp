#include <vector>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;

/*2022.03.10
�ϴ� ���������� ���� �κ��� �־��µ� �װ� ���γ� ���� ���̰� 1�� ��쿡 ������ ���� �ƴ�����
���̶�� �Ǵ��ϴ� ��찡 �־���. �׷��� ���γ� ���� ���̰� 1�� ��쿡�� map�� �̿��� ������ �������.
�ٵ� �׽�Ʈ ���̽� 5������ ������.*/

bool visit[51][51];
int line[51][51], answer;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
map<pair<pair<int, int>, pair<int, int>>, bool> connect;

void dfs(int x, int y, int dist, int targetX, int targetY) {
	if (x == targetX && y == targetY) {
		if (answer > dist)
			answer = dist;
		return;
	}
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx > 50 || ny > 50) continue;
		if (visit[nx][ny] || line[nx][ny] != 1) continue;
		if (connect[{ {x, y}, { nx, ny }}]) continue;
		dfs(nx, ny, dist + 1, targetX, targetY);
	}
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	answer = 987654321;
	memset(line, -1, sizeof(line));
	for (auto r : rectangle) {
		int minX = r[0], minY = r[1], maxX = r[2], maxY = r[3];
		for (int i = minX; i <= maxX; i++) {
			for (int j = minY; j <= maxY; j++) {
				if (line[i][j] == 0) continue;
				if (i == minX || i == maxX || j == minY || j == maxY) line[i][j] = 1;
				else line[i][j] = 0;
			}
		}
		if (maxX - minX == 1)
			for (int i = minY + 1; i < maxY; i++) {
				connect[{ {minX, i}, { maxX, i }}] = true;
				connect[{ {maxX, i}, { minX, i }}] = true;
			}
		if (maxY - minY == 1)
			for (int i = minX + 1; i < maxX; i++) {
				connect[{ {i, minY}, { i, maxY }}] = true;
				connect[{ {i, maxY}, { i, minY }}] = true;
			}
				
	}
	dfs(characterX, characterY, 0, itemX, itemY);
	return answer;
}

int main() {
	cout << solution({ {2, 3, 7, 4}, {2, 5, 7, 6}, {3, 2, 4, 7}, {5, 2, 6, 7} }, 1, 4, 6, 3);
}