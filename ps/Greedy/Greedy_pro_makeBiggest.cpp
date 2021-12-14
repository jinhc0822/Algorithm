#include <string>
#include <iostream>
using namespace std;

/*2021.12.14
슬라이드 윈도우를 사용해서 풀었다. 다른 사람들 답을 보니 이게 정석인 것 같다.
굉장히 특이한 방법으로 푼 사람도 있었다. 밑에 있는 코드인데 어떻게 이런 생각을 했을까..
greedy인 이유는 가장 각 시점에서 가장 큰 수를 고르면 되기 때문에 그렇게 분류를 한 것 같다.*/

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int start = 0, end = k;
    while (end < len) {
        int m = -1, idx;
        for (int i = start; i <= end; i++) {
            if (number[i] > m) {
                m = number[i];
                idx = i;
            }
        }
        answer += m;
        start = idx + 1;
        end++;
    }
    return answer;
}
/*
string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k);
    for (int i = k - 1; i >= 0; i--) {
        int j = 0;
        do {
            // 이건 내가 넣음. 원래 없었는데 그럼 "999", 2에 오류 생겨서 넣음.
            // if (j > answer.length() - 1) break; 
            if (number[i] >= answer[j]) {
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }
            else 
                break;
        } while (true);
    }
    return answer;
}*/