#include <iostream>
#include <vector>
using namespace std;

/*2021.12.08
������ ����� �ʾҴµ�.. ans�� Ÿ���� long long���� ����� �ϴ� �� ��Ű� �־���...
long long ���� ���� �ʹ� �������̶� Ÿ�� Ȯ���� �����ϰ� �־���..*/

int n, k;
vector<int> student;
int len[21];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		student.push_back(s.length());
	}
	long long ans = 0;
	int start = 0, end = (k == n) ? k - 1 : k;
	for (int i = start + 1; i <= end; i++)
		len[student[i]]++;
	ans += len[student[start]];
	start++; end++;
	while (start < n - 1) {
		len[student[start]]--;
		if (end < n) len[student[end]]++;
		ans += len[student[start]];
		start++; end++;
	}
	cout << ans;
}