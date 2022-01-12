#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*2022.01.12
카카오 문제 특) 완전탐색 좋아함. 방법은 뻔히 보이는데 코드를 어떻게 짜는 데 구상하는게 엄청 오래 걸림..
하나하나 생각을 많이 해야했다. 이 문제가 설마 완전탐색이라고는 생각 못했는데...
시작하는 위치 다르게 해보고, 밖에 나가는 친구들 순서만 순열로 달리해보고 했는데 둘 다 틀려서 두 개를 합쳤는데
그게 정답이었다.. 그리고 문제 해결의 중심은 greedy하게 가장 가까이 있는 위치를 골라서 가는 것이었다.
이건 최근에 푼 그리디 문제랑 비슷해서 유추하기 쉬웠다.*/

int N;
bool visit[201] = { false, };

pair<int, int> nearest(int k) {
	int cur = k, cnt = 0;
	pair<int, int> rightNear, leftNear;
	while (true) {
		cur++;
		cnt++;
		if (cur == N)
			cur = 0;
		if (cnt == N)
			return { N, 1000 };
		if (visit[cur]) {
			rightNear = { cur, cnt };
			break;
		}
	}
	cur = k; cnt = 0;
	while (true) {
		cur--;
		cnt++;
		if (cur == -1)
			cur = N - 1;
		if (cnt == N)
			return { N, 1000 };
		if (visit[cur]) {
			leftNear = { cur, cnt };
			break;
		}
	}
	return (leftNear.second < rightNear.second) ? leftNear : rightNear;
}
int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 100;
	N = n;
	sort(dist.begin(), dist.end());
	for (int pos : weak) {
		do {
			int cur = pos;
			int res = 100;
			memset(visit, false, sizeof(visit));
			for (int p : weak)
				visit[p] = true;
			for (int f = 0; f < dist.size(); f++) {
				visit[cur] = false;
				int d = 0;
				pair<int, int> next;
				while (true) {
					next = nearest(cur);
					cur = next.first;
					if (d + next.second > dist[f])
						break;
					visit[cur] = false;
					d += next.second;
				}
				bool chk = true;
				for (int i : weak)
					if (visit[i]) {
						chk = false;
						break;
					}
				if (chk) {
					res = f + 1;
					break;
				}
			}
			if (res < answer)
				answer = res;
		} while (next_permutation(dist.begin(), dist.end()));
	}
	if (answer == 100)
		return -1;
	return answer;
}