#include <vector>
#include <queue>
using namespace std;

/*2021.12.15
처음에는 진입 구간이 제일 빠른 순으로 정렬을 했는데 생각해보니
진출 구간이 빠른 순서로 하는 게 맞는 거 같더라..
굳이 proirity_queue 쓸 필요는 없는데 그러면 sort에 comp 함수를 만들어야함.*/

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<pair<int, int>> route;
    for (int i = 0; i < routes.size(); i++)
        route.push({ -routes[i][1], routes[i][0] });
    while (!route.empty()) {
        int e = -route.top().first;
        route.pop();
        while (true) {
            if (route.empty())
                break;
            if (route.top().second <= e)
                route.pop();
            else
                break;
        }
        answer++;
    }
    return answer;
}