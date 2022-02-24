#include <queue>
#include <cmath>
using namespace std;

/*2022.02.22
다른 풀이들은 다 dfs로 풀었더라..
내가 한 방법하고 똑같은데 난 왜 안되지?..
bfs랑 dfs랑 속도가 같은 걸로 알고 있는데 왜 안 되는지 잘 모르겠다.
구조체를 생성하는 데에 시간이 많이 걸리나?.. 아니면 큐를 사용하는게 문젠가?
예제 테스트는 다 통과하는데..
그래도 내가 푼 방식이 다른 사람들 답이랑 똑같았을 때 뿌듯했다. 나름 고민을 좀 한거라..*/

int answer = 0;
void dfs(int n, int cnt) {
	if (n == 1 && cnt == 0) {
		answer++;
		return;
	}
	if (n<1 || pow(3, (cnt + 1) / 2)>n)
		return;
	if (cnt >= 2 && n % 3 == 0)
		dfs(n / 3, cnt - 2);
	dfs(n - 1, cnt + 1);
}
int solution(int n) {
	answer = 0;
	dfs(n - 2, 2);
	return answer;
}

/*struct Info {
	int left;
	int num;
};
int solution(int n) {
	int answer = 0;
	int powThree[20];
	for (int i = 0, k = 1; i < 20; i++, k *= 3)
		powThree[i] = k;
	queue<Info> q;
	q.push({ 2, n - 2 }); // 마지막엔 무조건 ++이기 때문
	while (!q.empty()) {
		Info cur = q.front();
		q.pop();
		if (cur.num == 1 && cur.left == 0) {
			answer++;
			continue;
		}
		// 써야하는 *의 개수가 현재 수보다 클 경우 불가능
		if (cur.num < 1 || cur.num < powThree[(cur.left + 1) / 2])
			continue;
		if (cur.left >= 2 && cur.num % 3 == 0)
			q.push({ cur.left - 2, cur.num / 3 });
		q.push({ cur.left + 1, cur.num - 1 });
	}
	return answer;
}*/