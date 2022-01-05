#include <string>
#include <vector>
#include <queue>
using namespace std;

/*2022.01.05*/

struct Info {
    int y, x, dist, left, curNum;
    Info(int a, int b, int c, int d, int e = -1) {
        y = a; x = b; dist = c; left = d; curNum = e;
    }
};

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    queue<Info> q;
    bool card[7] = { false, };
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            card[board[i][j]] = true;
    int n = 0;
    for (int i = 1; i < 7; i++)
        if (card[i])
            n++;
    q.push(Info(r, c, 0, n));
    while (!q.empty()) {
        Info cur = q.front();
        q.pop();
        if (cur.left == 0) {
            answer = cur.dist;
            break;
        }
    }
    return answer;
}