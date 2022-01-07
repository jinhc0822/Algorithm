#include <string>
#include <vector>
using namespace std;

/*2022.01.06
���� �� �־����� �ϴ� ���� ���� ����. �ذ� ����� �˰ڴµ�(��� �װ͵� ������ ��û ����� �߻��̾���.)
���� ����� ������ �𸣰ھ ���� �ô�.. �� �ð��� �� ������ �� �ٲٴ� �⺻���� ������ ���� ��������?..
�Դٰ� �������� �̿��ؼ� Ǫ�� ����̶��.. ������ ���ߴ�. �ణ ���..*/

int t[360000];

int str2sec(string s) {
    int res = 0;
    res += 3600 * stoi(s.substr(0, 2));
    res += 60 * stoi(s.substr(3, 2));
    res += stoi(s.substr(6, 2));
    return res;
}
string sec2str(int n) {
    string res = "";
    int s = n % 60; n /= 60;
    int m = n % 60; n /= 60;
    int h = n;
    if (h < 10) res += "0";
    res += to_string(h);
    res += ":";

    if (m < 10) res += "0";
    res += to_string(m);
    res += ":";

    if (s < 10) res += "0";
    res += to_string(s);

    return res;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (string s : logs) {
        int start = str2sec(s.substr(0, 8));
        int end = str2sec(s.substr(9));
        for (int i = start + 1; i <= end; i++)
            t[i]++;
    }
    int wholeTime = str2sec(play_time);
    int advTime = str2sec(adv_time);

    long long curTime = 0;
    long long maxTime = 0;
    int Time = 1;
    for (int i = 1; i <= advTime; i++) {
        curTime += t[i];
        maxTime += t[i];
    }
    for (int i = 2; i <= wholeTime - advTime + 1; i++) {
        curTime += (long long)(t[i + advTime - 1] - t[i - 1]);
        if (curTime > maxTime) {
            maxTime = curTime;
            Time = i;
        }
    }
    answer = sec2str(Time - 1);
    return answer;
}