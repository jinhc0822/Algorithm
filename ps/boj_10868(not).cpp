#include <iostream>
using namespace std;

/*2022.04.18*/

int n, m, num[100000];
pair<int, int> p[100000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < m; i++)
		cin >> p[i].first >> p[i].second;
}