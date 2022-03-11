#include <vector>
#include <cstring>
#include <map>
using namespace std;

/*2022.03.10
일단 예제에서도 막힌 부분이 있었는데 그건 세로나 가로 길이가 1인 경우에 실제로 길이 아니지만
길이라고 판단하는 경우가 있었다. 그래서 가로나 세로 길이가 1인 경우에만 map을 이용해 연결을 끊어줬다.
근데 테스트 케이스 5개에서 막혔다. 다른 도형 간의 사이의 길이가 1일 경우 똑같은 문제가 생겼다.
그래서 비트마스킹을 이용하여 각 도형의 점들을 구분해주었다. 
다른 풀이를 보니 그냥 스케일을 2배로 해서 푼 것도 있었다. 사실 이게 가장 간단한 풀이가 아닐까 싶다.*/

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
		if (visit[nx][ny] || line[nx][ny] < 1) continue;
		if (connect[{ {x, y}, { nx, ny }}]) continue;
		if ((line[x][y] & line[nx][ny]) == 0) continue;
		dfs(nx, ny, dist + 1, targetX, targetY);
	}
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	answer = 987654321;
	memset(line, 0, sizeof(line));
	int num = 0;
	for (auto r : rectangle) {
		int minX = r[0], minY = r[1], maxX = r[2], maxY = r[3];
		for (int i = minX; i <= maxX; i++) {
			for (int j = minY; j <= maxY; j++) {
				if (line[i][j] == -1) continue;
				if (i == minX || i == maxX || j == minY || j == maxY) line[i][j] |= (1 << num);
				else line[i][j] = -1;
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
		num++;
	}
	dfs(characterX, characterY, 0, itemX, itemY);
	return answer;
}