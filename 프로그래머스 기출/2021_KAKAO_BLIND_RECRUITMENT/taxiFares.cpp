#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/*2022.01.05
최단거리 구하는 알고리즘을 알고 있으면 매우 쉬운 문제. 다익스트라로 풀었음.
근데 처음에 모든 정점에 대해 다익스트라를 돌렸더니 두 개의 효율성 테스트에서 시간초과가 뜸.
그래서 dist[a][b]=dist[b][a]임을 이용해서 s, a, b 정점에 대해서만 다익스트라로 풀었더니 풀렸음.
사소한 방식이지만 200번 연산을 3번 연산으로 줄일 수 있는 방법이었다.*/

int dist[201][201];
vector<pair<int, int>> v[201];

void distance(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start][start] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nCost = v[cur][i].second;
            if (dist[start][next] > cost + nCost) {
                dist[start][next] = cost + nCost;
                pq.push(make_pair(-dist[start][next], next));
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = INF;
    for (auto k : fares) {
        v[k[0]].push_back(make_pair(k[1], k[2]));
        v[k[1]].push_back(make_pair(k[0], k[2]));
    }
    distance(s);
    distance(a);
    distance(b);
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        if (dist[s][i] != INF && dist[a][i] != INF && dist[b][i] != INF)
            tmp = dist[s][i] + dist[a][i] + dist[b][i];
        else
            tmp = INF;
        if (answer > tmp)
            answer = tmp;
    }
    return answer;
}