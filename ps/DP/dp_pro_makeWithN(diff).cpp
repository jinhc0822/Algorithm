#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

/*2021.12.07
어제 풀다가 어떻게 풀지 감을 잡지 못해서 답을 봄. 밑의 코드는 인터넷에 있던 다른 분의 코드이다.
N을 i번 사용해 만들 수 있는 숫자는 (N을 j번 사용해 만들 수 있는 숫자)+(k번 사용해 만들 수 있는 숫자)
임을 이용해 dp를 만든 것이 참신했다. 사칙연산이라는 것에 빠져서 괄호를 어떻게 처리하면 좋을까에만
너무 고민을 한 것 같다. 재귀를 통해서 부분문제를 만들어 풀려고 했지만... 방법이 잘못된 것 같다.
set을 쓴 이유는 중복이 허용되지 않기 때문에 find를 쓸 때 시간을 줄일 수 있기 때문이다. */

int solution(int N, int number) {
    if (N == number) return 1;
    // arr[i]는 N이 (i + 1)번 쓰였을 때 가능한 숫자
    vector<set<int>> arr(8);
    //"N"*(i+1)로 초기화
    for (int i = 0; i < 8; i++) {
        int n = 0;
        int digit = i;
        while (digit >= 0)
            n += N * pow(10, digit--);
        arr[i].insert(n);
    }
    //[DP] 사칙연산으로 가능한 숫자 모두 확인
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            for (auto& x : arr[j]) {
                for (auto& y : arr[i - j - 1]) {
                    arr[i].insert(x + y);
                    arr[i].insert(x * y);
                    arr[i].insert(x - y);
                    if (y != 0) arr[i].insert(x / y);
                }
            }
        }
        //number가 있는지 확인
        if (arr[i].find(number) != arr[i].end()) {
            return i + 1;
        }
    }
    //1부터 8까지 중에 return 없을시 -1 return
    return -1;
}