#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

/*2022.01.04
구현문제이긴 한데 꽤나 애를 먹었다. 이렇게나 고생할 줄이야...
일단 문자열 파싱하는 방법을 몰라서 찾아봤다... find랑 erase를 이용하려고 했는데 더 좋은 방법을 찾고 싶었다.
https://myprivatestudy.tistory.com/48 여기에 잘 정리되어 있더라..
처음에 시간초과가 걸렸는데 문제는 stoi였다. for문 안에 stoi를 넣었더니 시간초과가 났다..*/

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> applicant[3][2][2][2];
    map<string, int> in;
    in.insert({ "cpp", 0 });
    in.insert({ "java", 1 });
    in.insert({ "python", 2 });
    in.insert({ "backend", 0 });
    in.insert({ "frontend", 1 });
    in.insert({ "junior", 0 });
    in.insert({ "senior", 1 });
    in.insert({ "chiken", 0 });
    in.insert({ "pizza", 1 });
    for (int i = 0; i < info.size(); i++) {
        string s = info[i], t;
        stringstream ss(s);
        vector<string> v;
        while (getline(ss, t, ' ')) {
            v.push_back(t);
        }
        applicant[in[v[0]]][in[v[1]]][in[v[2]]][in[v[3]]].push_back(stoi(v[4]));
    }

    for (int i = 0; i < query.size(); i++) {
        string s = query[i], t;
        stringstream ss(s);
        vector<string> v;
        while (getline(ss, t, ' ')) {
            v.push_back(t);
        }
        int first = (v[0] != "-") ? 1 : 3;
        int second = (v[2] != "-") ? 1 : 2;
        int third = (v[4] != "-") ? 1 : 2;
        int fourth = (v[6] != "-") ? 1 : 2;
        int cnt = 0;
        for (int a = 0; a < first; a++) {
            if (first == 1)
                a = in[v[0]];
            for (int b = 0; b < second; b++) {
                if (second == 1)
                    b = in[v[2]];
                for (int c = 0; c < third; c++) {
                    if (third == 1)
                        c = in[v[4]];
                    for (int d = 0; d < fourth; d++) {
                        if (fourth == 1)
                            d = in[v[6]];
                        int k = stoi(v[7]);
                        for (int app : applicant[a][b][c][d]) {
                            if (app >= k)
                                cnt++;
                        }

                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}