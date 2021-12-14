#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.14
이 문제를 굳이 greedy 항목에 넣어서 답을 도출해 사람들을 혼란에 빠뜨리는 것 같다.
greedy algorithm이 항상 최적해를 도출하는 것은 아니지만 굳이 완전 탐색으로 
최적해를 도출할 수 있는 문제에 greedy라는 분류를 넣어서 헷갈리게 만든 의도는 무엇일까..
왜 n-1에서 오른쪽은 0이라고 명시하지 않았는지 궁금하다. 이런 제한을 왜 둔 것인지 모르겠다.
뭔가 다른 문제는 테스트 케이스에 대해서만 질문하는데 이 문제는 문제의 타당성에 대해
제기하는 질문이 굉장히 많다. 뭔가 이상한 문제는 맞는거 같은..

이 풀이는 인터넷에서 본 것인데 정확하진 않지만 이 풀이도 greedy인지 잘 모르겠다. 일단 코테는 맞았는데.
(원점)이 원점, {(a), (b)}가 'A'가 아닌 문자의 위치라고 할 때 이 모든 위치를 가면서 최소 이동 거리가 우리가 구하고자 하는 값이다.
(위치가 최소 2개가 필요해서 그렇지 2개보다 많을 경우에도 똑같은 원리가 적용된다.)
그 값의 경로는 두 가지가 될 수 있다. (원점)(a)(원점)(b)와 (원점)(b)(원점)(a)가 될 수 있다. 
(사실 이 문제에서는 앞에서 말한 제한이 있어서 두번째 경우는 해당하는지 잘 모르겠다.)
그래서 이 코드의 for문에서 모든 ('A'가 아닌 문자의 위치)를 (a), (b)로 설정하면서 (*) 부분에서 첫번째 경우가 짧은지 두번째 경우가 짧은지 
탐색하는 것이다. 결국 이 풀이는 완전탐색이 아닐까?.. 답도 최솟값으로 나온다.*/

int solution(string name) {
    int answer = 0;
    for (char ch : name)
        answer += min(ch - 'A', 91 - ch);
    int len = name.length();
    int move = len - 1;
    int next;
    for (int i = 0; i < len; i++) {
        next = i + 1;
        while (next < len && name[next] == 'A') next++;
        move = min(move, i + (len - next) + min(i, len - next)); // (*)
    }
    answer += move;
    return answer;
}