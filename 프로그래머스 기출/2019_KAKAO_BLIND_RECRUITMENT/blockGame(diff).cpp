﻿#include <vector>
using namespace std;

/*나중에 다시 돌아와서 풀기.
주어진 블록 중에서 검은 블록을 위에서 떨어뜨려도 직사각형을 만들 수 없는 블록이 있는 것까지는 쉽게 파악할 수 있다.
그리고 직사각형을 만들 수 있는 블록의 경우에 어디를 채워야 직사각형을 만들 수 있는지 미리 코드를 짠 다음에 board 위의
블록이 그러한 블록인지만 판별한다면 쉽게 풀리는 문제라고 생각했다.
하지만 
0 0 0 1
0 2 1 1
2 2 2 1
같은 경우에 한 번에 2개의 블록이 없어지는가에 대한 의문이 계속 떠올랐고 만약 이게 가능하다면 코드는 훨씬 복잡지지 않을까 생각했다.
나와 같은 생각을 한 사람의 질문에서 답변을 얻었다.
그런 경우는 없다고 생각하고 문제를 풀어도 답이 나온다고 한다. 이 부분은 좀 문제가 있는게 아닌가?...
1 0 0 0
1 1 0 0
1 2 2 2
0 0 0 2
이 경우에도 1번 블록은 위에 말한 직사각형을 만들 수 없는 블록 중 하나인데 이게 된다면 코드가 좀 복잡해지긴 한다.
그냥 하나의 블록에만 집중해서 문제를 풀어야할 것 같다.*/

int solution(vector<vector<int>> board) {
	int answer = 0;
	return answer;
}