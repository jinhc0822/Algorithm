#include <vector>
#include <cstring>
#define MOD 1000000007
using namespace std;

/*2021.12.06
어렵진 않은 문제. 근데 보통의 문제들이랑 다르게 y랑 x값을 반대로 준다. 
행열 순서가 아닌 좌표평면으로 열행순으로 좌표를 줘서 순간 헷갈렸다.
그리고 ret의 값이 MOD를 넘어가면 효율성 테스트에서 감점을 받기 때문에
마지막에 %=을 해줘서 ret 값도 바꿔줘야 맞을 수 있다. 굳이 그걸 왜 따지는진 잘 모름.*/

int M, N;
bool pud[101][101];
int cache[101][101];

int wayToSchool(int y, int x) {
    if (y == N && x == M) return 1;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    cache[y][x] = 0;
    if (x + 1 <= M && !pud[y][x + 1]) ret += wayToSchool(y, x + 1);
    if (y + 1 <= N && !pud[y + 1][x]) ret += wayToSchool(y + 1, x);
    return ret %= MOD; // 이 부분
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++)
        pud[puddles[i][1]][puddles[i][0]] = true;
    M = m; N = n;
    memset(cache, -1, sizeof(cache));
    answer = wayToSchool(1, 1);
    return answer;
}