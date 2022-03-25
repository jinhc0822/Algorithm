#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.25
별로 좋아하지 않는 유형의 구현문제... 그냥 구현하면 됨..*/

struct Info{
	int r;
	int c;
	int s;
};
int n, m, k, answer = 987654321;
int A[50][50], copyA[50][50];
vector<Info> rot;
vector<int> v;

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			copyA[i][j] = A[i][j];
}
void rotation(int y1, int x1, int y2, int x2) {
	int tmp, tmp2;
	tmp = copyA[y1][x2];
	for (int i = x2; i > x1; i--)
		copyA[y1][i] = copyA[y1][i - 1];

	tmp2 = copyA[y2][x2];
	for (int i = y2; i > y1 + 1; i--)
		copyA[i][x2] = copyA[i - 1][x2];
	copyA[y1 + 1][x2] = tmp;

	tmp = copyA[y2][x1];
	for (int i = x1; i < x2 - 1; i++)
		copyA[y2][i] = copyA[y2][i + 1];
	copyA[y2][x2 - 1] = tmp2;
	
	for (int i = y1; i < y2 - 1; i++)
		copyA[i][x1] = copyA[i + 1][x1];
	copyA[y2 - 1][x1] = tmp;
}
int value() {
	int res = 987654321;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum += copyA[i][j];
		res = min(res, sum);
	}
	return res;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rot.push_back({ r, c, s });
	}
	for (int i = 0; i < k; i++)
		v.push_back(i);
	do {
		copy();
		for (int i = 0; i < k; i++) {
			int r = rot[v[i]].r - 1;
			int c = rot[v[i]].c - 1;
			int s = rot[v[i]].s;
			for (int j = 1; j <= s; j++)
				rotation(r - j, c - j, r + j, c + j);
		}
		int val = value();
		answer = min(answer, val);
	} while (next_permutation(v.begin(), v.end()));
	cout << answer;
}