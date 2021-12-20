#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.20
이 문제는 뭐지... 처음에는 센서 사이의 거리를 정렬해서 큰 순서대로 
k-1개를 잘라내면 되지 않을까 하고 생각했는데 그렇게 하면 안되는 경우가 있었다. 
그래서 결국 답을 봤는데 내 풀이 방법은 맞았고 아까 확인하는 과정에서 약간 실수가
있었나 보다. 왜 지금 확인해보니 맞지?.. 약간 허탈하긴 하네.. 어째 정답률이 높더라니..*/

int n, k, ans;
int sensor[10001], dist[10001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> sensor[i];
	sort(sensor, sensor + n);
	for (int i = 0; i < n - 1; i++)
		dist[i] = sensor[i + 1] - sensor[i];
	sort(dist, dist + n - 1);
	for (int i = 0; i < n - k; i++)
		ans += dist[i];
	cout << ans;
}