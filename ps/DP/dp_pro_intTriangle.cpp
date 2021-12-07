#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.06
쉬움. 재귀형이 아니라 반복형이 더 쉬울 것 같아 이렇게 했다.*/

int cache[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    cache[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) cache[i][j] = cache[i - 1][j] + triangle[i][j];
            else if (j == i) cache[i][j] = cache[i - 1][j - 1] + triangle[i][j];
            else cache[i][j] = max(cache[i - 1][j - 1], cache[i - 1][j]) + triangle[i][j];
        }
    }
    int sz = triangle.size();
    for (int i = 0; i < sz - 1; i++)
        answer = max(answer, cache[sz - 1][i]);
    return answer;
}