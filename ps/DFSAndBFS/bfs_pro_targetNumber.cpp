#include <vector>
#include <queue>
using namespace std;

/*2021.11.03
dfs로 했으면 더 좋았을거 같기도.. */

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = numbers.size();
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int num = q.front().first;
        int idx = q.front().second;
        q.pop();
        if (idx == size) {
            if (num == target) answer++;
            continue;
        }
        q.push(make_pair(num + numbers[idx], idx + 1));
        q.push(make_pair(num - numbers[idx], idx + 1));
    }
    return answer;
}