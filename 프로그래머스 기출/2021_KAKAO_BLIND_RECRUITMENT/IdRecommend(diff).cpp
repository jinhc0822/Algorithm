#include <string>
#include <vector>
using namespace std;

/*2022.01.04
string 클래스의 내장함수를 잘 알고 있어야하는 문제. answer[answer.size()-1]보다
answer.front를 사용하는 것이 훨씬 좋았을 것 같다.*/

string solution(string new_id) {
    string answer = "";
    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if (c >= 'A' && c <= 'Z')
            new_id[i] = tolower(c);
    }
    // 2단계
    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if (!(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9') && c != '-' && c != '_' && c != '.')
            continue;
        answer += c;
    }
    // 3단계
    while (true) {
        int idx = answer.find("..");
        if (idx == string::npos)
            break;
        answer.replace(idx, 2, ".");
    }
    // 4단계
    if (answer[0] == '.')
        answer = answer.substr(1);
    if (answer[answer.size() - 1] == '.')
        answer.pop_back();
    // 5단계
    if (answer.empty())
        answer += 'a';
    // 6단계
    if (answer.size() >= 16)
        answer = answer.substr(0, 15);
    if (answer[answer.size() - 1] == '.')
        answer.pop_back();
    // 7단계
    if (answer.size() <= 2)
        while (answer.size() != 3)
            answer += answer[answer.size() - 1];
    return answer;
}