#include <iostream>
#include <vector>
using namespace std;

/*2022.01.03
쉬웠음.
둘 다 정렬해서 일일히 비교하는 작업을 하기 싫어서 same 배열을 사용했다.
0을 제외하면 same의 값은 1 또는 2가 나올 것이다.*/

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int same[46] = { 0, };
    int rnk[7] = { 6, 6, 5, 4, 3, 2, 1 };
    for (int i = 0; i < 6; i++) {
        same[lottos[i]]++;
        same[win_nums[i]]++;
    }
    for (int i = 1; i <= 45; i++)
        if (same[i] == 2)
            cnt++;
    answer.push_back(rnk[cnt + same[0]]);
    answer.push_back(rnk[cnt]);
    return answer;
}