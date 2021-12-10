#include <iostream>
#include <vector>
using namespace std;

/*2021.12.08
문제는 어렵지 않았는데.. ans의 타입을 long long으로 해줘야 하는 걸 헤매고 있었다...
long long 쓰는 것이 너무 오랜만이라 타입 확인을 깜빡하고 있었네..*/

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