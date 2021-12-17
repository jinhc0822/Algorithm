#include <iostream>
#include <string>
using namespace std;

/*2021.12.16
행렬이 처음부터 맞는 경우를 생각해내지 못해서.. 반례를 보았다..
저번에 풀 때는 풀이법조차 생각못했는데 그래도 좀 나아진 걸까?..*/

int n, m, ans;
char A[50][50], B[50][50];

void trans(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (A[i][j] == '0')
				A[i][j] = '1';
			else
				A[i][j] = '0';
		}
	}
	ans++;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			A[i][j] = s[j];
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			B[i][j] = s[j];
	}
	//처음부터 같다면 행렬의 크기에 상관없이 0을 출력
	bool chk = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] != B[i][j])
				chk = false;
	if (chk) {
		cout << 0;
		return 0;
	}
	//행렬의 크기가 3x3보다 작다면 -1을 출력
	if (n < 3 || m < 3) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n - 2; i++)
		for (int j = 0; j < m - 2; j++)
			if (A[i][j] != B[i][j])
				trans(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] != B[i][j]) {
				cout << -1;
				return 0;
			}
	cout << ans;
}