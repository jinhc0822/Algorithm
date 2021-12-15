#include <vector>
#include <queue>
using namespace std;

/*2021.12.15
ó������ ���� ������ ���� ���� ������ ������ �ߴµ� �����غ���
���� ������ ���� ������ �ϴ� �� �´� �� ������..
���� proirity_queue �� �ʿ�� ���µ� �׷��� sort�� comp �Լ��� ��������.*/

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