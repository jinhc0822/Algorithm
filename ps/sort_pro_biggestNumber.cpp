#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/*초반에는 법칙을 찾겠다고 좀 특이한 방법으로 comp 함수를 짰었는데 반례를 
찾던 도중 그냥 이렇게 풀면 되지 않나 하는 생각이 들어 지금 comp로 바꿨다. 
하지만 케이스 하나에서 계속 틀렸고 반례 찾느라 30분 동안 헤매다가 결국 질문
글에서 해당 반례를 보고 정답을 맞췄다. 해당 반례가 입력으로 0만 여러개 들어올 
때 였는데 양 극단 값을 확실하게 넣어보지 않은 게 잘못인 것 같다.*/

bool comp(int a, int b) {
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    int A = stoi(s1);
    int B = stoi(s2);
    return A < B;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    string answer = "";
    if (numbers.back() == 0) return "0";
    for (int i = numbers.size() - 1; i >= 0; i--)
        answer += to_string(numbers[i]);
    return answer;
}