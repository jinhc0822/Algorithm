#include <string>
#include <vector>
using namespace std;

/*2022.01.06
아직 난 멀었구나 하는 것을 느낀 문제. 해결 방법은 알겠는데(사실 그것도 구현은 엄청 어려운 발상이었다.)
구현 방법을 도무지 모르겠어서 답을 봤다.. 왜 시간을 초 단위로 다 바꾸는 기본적인 생각을 하지 못했을까?..
게다가 누적합을 이용해서 푸는 방법이라니.. 생각도 못했다. 약간 멘붕..*/

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