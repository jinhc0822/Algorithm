#include <string>
#include <queue>
#include <vector>
using namespace std;

/*2021.11.03
쉬움*/

int solution(string begin, string target, vector<string> words) {
    int len = words[0].length();
    bool visit[50] = { false, };
    bool firstChange[50] = { false, };
    for (int i = 0; i < words.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < len; j++)
            if (begin[j] != words[i][j])
                cnt++;
        if (cnt == 1)
            firstChange[i] = true;
    }
    bool canChange[50][50] = { false, };
    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            int cnt = 0;
            for (int k = 0; k < len; k++)
                if (words[i][k] != words[j][k])
                    cnt++;
            if (cnt == 1) {
                canChange[i][j] = true;
                canChange[j][i] = true;
            }
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < words.size(); i++) {
        if (firstChange[i]) {
            q.push(make_pair(i, 1));
            visit[i] = true;
        }
    }
    while (!q.empty()) {
        int curWord = q.front().first;
        int curTrans = q.front().second;
        q.pop();
        if (words[curWord] == target) return curTrans;
        for (int i = 0; i < words.size(); i++) {
            if (visit[i]) continue;
            if (!canChange[curWord][i]) continue;
            visit[i] = true;
            q.push(make_pair(i, curTrans + 1));
        }
    }
    return 0;
}