#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

/*2022.01.05
모든 경우의 수를 따지는 문제였다.. 하면 어렵진 않은데 일단 문제가 너무 헷갈려서 문제 이해하는 데에 시간이 많이 걸렸다.
모든 경우의 수 따지는 문제는 그렇게 좋아하지 않는다.. 계속 이렇게 푸는 것을 부정하고 다른 방법을 찾느라 시간을 많이 썼다.
주어지는 orders 수가 적은 데에는 이유가 있네.*/

map<string, int> m;
set<string> s[11];
string order;
int n, sz;

void dfs(string cur, int idx, int cnt) {
    if (cnt == n) {
         m[cur]++;
        s[n].insert(cur);
        return;
    }
    for (int i = idx; i < sz; i++) {
        if (sz - i < n - cnt)
            break;
        dfs(cur + order[i], i + 1, cnt + 1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        order = orders[i];
        sz = order.size();
        for (int c : course) {
            n = c;
            dfs("", 0, 0);
        }
    }
    for (int c : course) {
        int k = 0;
        for (string st : s[c]) {
            if (k < m[st])
                k = m[st];
        }
        for (string st : s[c]) {
            if (m[st] == k && k != 1)
                answer.push_back(st);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}