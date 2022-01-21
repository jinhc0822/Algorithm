#include <string>
#include <cmath>
using namespace std;

/*2022.01.21
쉬움.*/

int solution(string dartResult) {
	int answer = 0;
	int score[3];
	for (int i = 0, idx = -1; i < dartResult.size(); i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			idx++;
			if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
				score[idx] = 10;
				i++;
			}
			else
				score[idx] = dartResult[i] - '0';
		}
		if (dartResult[i] == 'D')
			score[idx] = pow(score[idx], 2);
		else if (dartResult[i] == 'T')
			score[idx] = pow(score[idx], 3);
		else if (dartResult[i] == '*') {
			if (idx == 0) {
				score[idx] *= 2;
			}
			else {
				score[idx] *= 2;
				score[idx - 1] *= 2;
			}
		}
		else if (dartResult[i] == '#')
			score[idx] *= -1;
	}
	answer = score[0] + score[1] + score[2];
	return answer;
}