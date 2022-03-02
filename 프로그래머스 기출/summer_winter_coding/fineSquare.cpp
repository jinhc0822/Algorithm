#include <cmath>
using namespace std;

/*2022.03.02
아니 나름 그래도 고민해서 floor 함수 사용해서 풀었는데 최대공약수로도 풀 수 있고 
(int)h*i/w를 answer에 더하고 answer*2를 반환하는 식도 있었다. 이건 좀 참신하네.*/

long long solution(int w, int h) {
	long long cnt = 0;
	for (int i = 0; i < w; i++) {
		double y1 = (double)h * i / (double) w;
		double y2 = (double)h * (i + 1) / (double)w;
		cnt += floor(y2) - floor(y1);
		if (y2 != floor(y2))
			cnt++;
	}
	return (double)w * (double)h - cnt;
}