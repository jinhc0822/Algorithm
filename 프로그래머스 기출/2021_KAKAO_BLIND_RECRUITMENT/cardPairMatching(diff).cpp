#include <string>
#include <vector>
#include <queue>
using namespace std;

/*2022.01.06
처음에 했던 방식은 visit[짝맞춘 카드 집합 비트마스킹][y][x][지금 찾고 있는 카드]를 이용해서 무식하게 bfs로 밀고 가는 
풀이였는데 어느 부분에서 틀리는지 발견을 못했다. bfs가 디버깅이 쉬운 알고리즘도 아니고 해서.. 게다가 저 visit으로 모든 경우의 수를 커버할 수 있다는 확신이 없었다.
웬만하면 될거 같은데 시간이 너무 많이 들 것 같다.
그래서 다른 분의 코드를 참고해서 풀이방법을 대강 알고 풀었다.*/

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 0;
	return answer;
}