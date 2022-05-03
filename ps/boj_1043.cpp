#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*2022.05.03
쉬움.*/

int n, m, ans;
bool knowTruth[51], visit[50];
//party[i] : i번 파티에 온 사람들, partyNum[i] : i번이 참가한 파티
vector<int> party[50], partyNum[51];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		knowTruth[a] = true;
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			party[i].push_back(b);
			partyNum[b].push_back(i);
		}
	}
	queue<pair<int, bool>> q; // 1이면 사람, 0이면 파티
	for (int i = 1; i <= n; i++)
		if (knowTruth[i])
			q.push({ i, true });
	while (!q.empty()) {
		int cur = q.front().first;
		bool isHuman = q.front().second;
		q.pop();
		if (isHuman) {
			for (int i = 0; i < partyNum[cur].size(); i++) {
				int next = partyNum[cur][i];
				if (visit[next]) continue;
				visit[next] = true;
				q.push({ next, false });
			}
		}
		else {
			for (int i = 0; i < party[cur].size(); i++) {
				int next = party[cur][i];
				if (knowTruth[next]) continue;
				knowTruth[next] = true;
				q.push({ next, true });
			}
		}
	}
	for (int i = 0; i < m; i++)
		if (!visit[i])
			ans++;
	cout << ans;
}