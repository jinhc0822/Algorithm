#include <iostream>
#include <string>
using namespace std;

/*2021.12.16
����� ó������ �´� ��츦 �����س��� ���ؼ�.. �ݷʸ� ���Ҵ�..
������ Ǯ ���� Ǯ�̹����� �������ߴµ� �׷��� �� ������ �ɱ�?..*/

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
	//ó������ ���ٸ� ����� ũ�⿡ ������� 0�� ���
	bool chk = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (A[i][j] != B[i][j])
				chk = false;
	if (chk) {
		cout << 0;
		return 0;
	}
	//����� ũ�Ⱑ 3x3���� �۴ٸ� -1�� ���
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