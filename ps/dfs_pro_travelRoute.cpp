#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.11.03
���� �ܰ迡�� �ð��� ���� �� ����. Ƽ���� ���� �������� �ʾƼ� �ð� �ʰ��� ���� �� �˾Ҵµ�
������ ������ �ʾҴ�. �������� ���� �� �� �ͼ��ؼ� ���������� tickets�� �����ߴµ� �׳� 
���� ȣ��� �ϸ� �� �������� �� ����. ���������� �Լ� ���ڿ� vector �ִ� ���� ���� �� �����ؼ�..�̷��� �ߴٸ�..*/

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