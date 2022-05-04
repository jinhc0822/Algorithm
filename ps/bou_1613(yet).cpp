#include <iostream>
#include <vector>
using namespace std;

/*2022.05.04
처음에는 위상정렬인줄 알았다. 
중간에 이걸 그냥 dfs나 bfs로 풀 수 있겠다고 생각하긴 했지만..(시간초과는 나중에 계산해보기로 하고)
하지만 위상정렬은 다른 집합은 고려하지 못해서 dfs를 이용해서 그룹을 지어주었다.
그룹이 아에 다르면 선수관계를 파악할 수 없는 것으로 하기 위해서이다. 근데 틀림.
같은 케이스에서 계속 틀리는 걸로 봐서 이게 문제가 아닌듯하다.. 
그룹이 문제가 아니었네ㅋㅋ; 한 노드에서 두 개의 가지로 뻗어나갈 때 그 가지들이 나중에
다시 합쳐진다면 그 가지들은 한 그룹에 있지만 가지끼리의 순서는 파악할 수 없다. 그냥 위상정렬을
사용하면 안 되는 문제였다.
다른 그래프 탐색으로는 시간초과가 걸린다고 하고 결국 답지에서 플로이드 워셜 알고리즘을
사용해야한다는 것을 알았다. 이 알고리즘은 최소거리를 구하는 알고리즘이라 생각도 안 해봤는데;;*/

int n, k, s;
int map[401][401];
vector<pair<int, int>> incident;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		map[a][b] = -1;
		map[b][a] = 1;
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b; cin >> a >> b;
		incident.push_back({ a, b });
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 0) {
					if (map[i][k] == 1 && map[k][j] == 1) map[i][j] == 1;
					else if (map[i][k] == -1 && map[k][j] == -1) map[i][j] = -1;
				}
			}
		}
	}
	for (int i = 0; i < s; i++)
		cout << map[incident[i].first][incident[i].second] << '\n';
}