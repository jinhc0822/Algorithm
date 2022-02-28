#include <vector>
#include <iostream>
#define INF 1234567890
using namespace std;

/*2022.02.28
처음엔 그래프 탐색으로 풀까 했는데 시간초과 걸릴 것도 뻔하고 남아있는 풍선 집합을 전달하는 것이 어려워서 포기하고
각 풍선마다 이게 어떤 식으로 터질까 고민했더니 풀렸다. 다른 답을 보니 스택으로 푼 분도 있더라.*/

int solution(vector<int> a) {
	vector<int> left(a.size());
	vector<int> right(a.size());
	int answer = 0;
	int leftMin = INF, rightMin = INF;
	left[0] = INF, right[a.size() - 1] = INF;
	for (int i = 1; i < a.size(); i++) {
		if (a[i - 1] < leftMin)
			leftMin = a[i - 1];
		left[i] = leftMin;
	}
	for (int i = a.size() - 2; i >= 0; i--) {
		if (a[i + 1] < rightMin)
			rightMin = a[i + 1];
		right[i] = rightMin;
	}
	for (int i = 0; i < a.size(); i++)
		if (!(a[i] > left[i] && a[i] > right[i]))
			answer++;
	return answer;
}