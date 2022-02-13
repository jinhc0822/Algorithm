#include <vector>
#include <queue>
using namespace std;

/*2022.02.10
이 코드는 미완성이다. 답지를 보고 할 의욕을 약간 잃었다.. bfs로 하면 안될거 같아서 그럼 뭘로 풀어야하나 모르겠어서 답지를 봤는데
bfs에서 함정의 활성화 여부까지 비트마스킹으로 큐에 넣어주는 걸로 풀었더라. 그거랑은 또 별개로 함정 노드에서 일반 노드로 갈 때랑 함정에서 함정 등등
4가지 경우에 bfs에 들어가는 방법이 다르기 때문에 경우를 잘 나눠서 코드를 짜야한다. 다음에 다시 풀 때 꼼꼼히 해보자.*/

struct Info {
    int num;
    int cost;
    bool go;
};
struct Node {
    vector<Info> adj;
    bool isTrap = false;
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 987654321;
    vector<int> visit(n + 1);
    vector<Node> node(n + 1);
    for (int i = 0; i < roads.size(); i++) {
        vector<int> v = roads[i];
        node[v[0]].adj.push_back({ v[1], v[2], true });
        node[v[1]].adj.push_back({ v[0], v[2], false });
    }
    for (int a : traps)
        node[a].isTrap = true;
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visit[start] = 1;
    while (!q.empty()) {
        int curNum = q.front().first;
        int dist = q.front().second;
        if (curNum == end) {
            if (dist < answer)
                answer = dist;
        }
        for
    }
    return answer;
}