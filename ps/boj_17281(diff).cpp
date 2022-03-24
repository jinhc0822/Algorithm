#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*2022.03.24
무조건 완전탐색, 구현이 맞다고 생각해서 풀었는데 시간초과 나왔다.. 그래서 분류를 봤더니 분류는 내가 생각한 
그대로였다. hit 함수에서 4번, 하나만 0이고 전부 홈런일 때 43번, 이닝의 수 최대 50번, 
그리고 정렬하는 순열의 수를 모두 곱하면 3억 5천 정도가 나오긴 한다... 어떤 방법으로 시간을 줄여아할까?
각 이닝의 결과가 전부 다를 수도 있기 때문에 순열을 건드는 것은 아닌것 같은데.. 이닝 수는 당연히 건드릴 수도 
없는 것이고. 스코어를 더하는 방식을 바꿔야할 것 같다.
곰곰히 생각해보니 한 이닝 내에서 친 타자 수에다가 이닝이 끝나고 남은 주자 수를 빼면 점수가 아닐까 하는 생각이
들어서 큐로 해결해보자 생각했다.
근데 막상 큐를 만들고 보니 이닝 안의 while문을 줄이지 않는 이상 시간이 크게 줄어들지 않을 것 같다고 생각했는데
역시나 1% 시간초과에서 50% 시간초과라는 차이가 있지만 시간초과가 났다.
그래서 다른 풀이들을 봤는데 내 풀이랑 다른 것도 없고 그냥 field 구현해서 일일히 다 if문으로 해결한 풀이도
통과했는데 왜 안되는 거지?? 똑같이 점수 구하는건 3번 정도 반복되는데 내 건 왜 시간초과가 나는지 모르겠다.
next_permutation이 재귀로 호출하는 것보다 시간이 빠르다는데 왜.. 포기..*/

vector<int> order, v = { 2, 3, 4, 5, 6, 7, 8, 9 };
int n, inning[50][10], answer;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 10; j++)
            cin >> inning[i][j];
    do {
        int score = 0;
        order.push_back(0);
        for (int i = 0; i < 9; i++) {
            if (i < 3) order.push_back(v[i]);
            else if (i == 3) order.push_back(1);
            else order.push_back(v[i - 1]);
        }
        int hitter = 1;
        for (int i = 0; i < n; i++) {
            int out = 0, cnt = 0;
            queue<bool> q;
            while (true) {
                int res = inning[i][order[hitter]];
                if (res == 0) out++;
                else {
                    for (int i = 0; i < res; i++) {
                        if (i == 0) q.push(true);
                        else q.push(false);
                        if (q.size() > 3) q.pop();
                    }
                    cnt++;
                }
                hitter++;
                if (hitter == 10)
                    hitter = 1;
                if (out == 3) break;
            }
            int k = 0;
            while (!q.empty()) {
                if (q.front())
                    k++;
                q.pop();
            }
            score += (cnt - k);
        }
        if (answer < score)
            answer = score;
        order.clear();
    } while (next_permutation(v.begin(), v.end()));
    cout << answer;
}