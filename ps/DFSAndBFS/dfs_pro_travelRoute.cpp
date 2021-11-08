#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.11.03
설계 단계에서 시간을 조금 쓴 문제. 티켓의 수가 나와있지 않아서 시간 초과가 나올 줄 알았는데
다행이 나오지 않았다. 전역변수 쓰는 게 더 익숙해서 전역변수로 tickets을 복사했는데 그냥 
참조 호출로 하면 더 괜찮았을 것 같다. 개인적으로 함수 인자에 vector 넣는 것을 별로 안 좋아해서..이렇게 했다만..*/

int s;
bool chk, visit[10000];
vector<vector<string>> t;
vector<string> v;

bool comp(vector<string> a, vector<string> b) {
    if (a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}
void dfs(string cur) {
    if (v.size() == s + 1) {
        chk = true;
        return;
    }
    for (int i = 0; i < s; i++) {
        if (t[i][0] != cur) continue;
        if (visit[i]) continue;
        v.push_back(t[i][1]);
        visit[i] = true;
        dfs(t[i][1]);
        if (chk) return;
        v.pop_back();
        visit[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    s = tickets.size();
    sort(tickets.begin(), tickets.end(), comp);
    t = tickets;
    v.push_back("ICN");
    dfs("ICN");
    return v;
}