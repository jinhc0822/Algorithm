#include <vector>
using namespace std;

/*2021.12.14
처음에는 여분을 챙긴 학생이 도난도 당했을 때 라는 조건을 그냥 무시하고 코드를 짰었다.
어차피 다른 사람에게 체육복을 주더라도 체육복을 입는 학생의 수는 같지 않나? 하고 생각했다.
하지만 그렇게 조건을 무시할 경우 3, {1, 2}, {2, 3}의 경우에 답이 잘못되게 된다.
다른 사람의 답을 보니 학생이 가지고 있는 체육복 수로 푼 풀이가 있던데 생각하지 못한 방법이었다.*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool lo[31] = { false, }, re[31] = { false, }, skip[31] = { false, };
    for (int i = 0; i < lost.size(); i++)
        lo[lost[i]] = true;
    for (int i = 0; i < reserve.size(); i++)
        re[reserve[i]] = true;
    for (int i = 1; i <= n; i++)
        if (lo[i] && re[i]) {
            answer++;
            re[i] = false;
            skip[i] = true;
        }
    for (int i = 1; i <= n; i++) {
        if (skip[i]) continue;
        if (!lo[i]) answer++;
        else {
            if (i != 1 && re[i - 1]) {
                answer++;
                re[i - 1] = false;
            }
            else if (i != n && re[i + 1]) {
                answer++;
                re[i + 1] = false;
            }
        }
    }
    return answer;
}