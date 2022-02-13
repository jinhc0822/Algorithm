#include <vector>
#include <queue>
using namespace std;

/*2022.02.10
�� �ڵ�� �̿ϼ��̴�. ������ ���� �� �ǿ��� �ణ �Ҿ���.. bfs�� �ϸ� �ȵɰ� ���Ƽ� �׷� ���� Ǯ����ϳ� �𸣰ھ ������ �ôµ�
bfs���� ������ Ȱ��ȭ ���α��� ��Ʈ����ŷ���� ť�� �־��ִ� �ɷ� Ǯ������. �װŶ��� �� ������ ���� ��忡�� �Ϲ� ���� �� ���� �������� ���� ���
4���� ��쿡 bfs�� ���� ����� �ٸ��� ������ ��츦 �� ������ �ڵ带 ¥���Ѵ�. ������ �ٽ� Ǯ �� �Ĳ��� �غ���.*/

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