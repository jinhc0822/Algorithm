#include <vector>
#include <climits>
using namespace std;

/*2022.03.14
처음에 문제를 보자마자 이분탐색이 생각났다. 근데 결국 이 문제는 풀지 못해 답을
봤는데 그 이유를 적어보고자 한다.
일단 추가해야하는 블록은 층이 높아질수록 증가하며 제거해야하는 블록은 층이 높아질수록
감소한다. 우리가 구하고자하는 것은 (추가해야하는 블록)*P+(제거해야하는 블록)*Q의 
최솟값이다. 결국 이 값은 어떻게 나올까?를 고민하다가 풀지 못했다. 다른 답을 보니
결국 이 값은 최대차항의 계수가 양수인 이차함수라고 증명을 해 놓았는데 이 증명이 없는
다른 분들은 어떻게 알고 푼거지?..
https://ydeer.tistory.com/78 이 분의 글에 많은 도움을 받았다. 다른 풀이도 있는데 
읽어보는 게 도움이 많이 될 것 같다. land의 수가 90000이니 각 값으로 풀 수 없을까
고민만 했었는데 이런 방법이 있을 줄이야..
근데 위의 글에 이차함수 증명에서 뭔가 이상한 점이 있긴하다. i가 어떻게 x가 들어간
식으로 나타내어지는거지;; y는 결국 i, x에 대한 방정식이지 않나?.. x가 i에 대한
증가함수이기 때문에 이차함수 라는 게 더 맞는 말 같다...*/

long long cal(long long h, vector<vector<int>>& land, int P, int Q) {
	long long res = 0;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			if (land[i][j] < h)
				res += (h - land[i][j]) * P;
			else if (land[i][j] > h)
				res += (land[i][j] - h) * Q;
		}
	}
	return res;
}
long long solution(vector<vector<int>> land, int P, int Q) {
	long long answer = 0;
	long long left = LLONG_MAX;
	long long right = 0 ,mid = 0;
	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			if (left > land[i][j]) left = land[i][j];
			if (right < land[i][j]) right = land[i][j];
		}
	}
	while (left <= right) {
		mid = (left + right) / 2;
		long long r1 = cal(mid, land, P, Q);
		long long r2 = cal(mid + 1, land, P, Q);
		if (r1 < r2) {
			answer = r1;
			right = mid - 1;
		}
		else {
			answer = r2;
			left = mid + 1;
		}
	}
	return answer;
}