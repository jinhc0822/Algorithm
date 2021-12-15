#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.14
투 포인터로 해결. 사람들을 다 태우고 남은 사람이 1명일 경우를 생각하지 못해서 조금 헤맸다.*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int start = 0, end = people.size() - 1;
    if (start == end)
        return answer = 1;
    while (start < end) {
        if (people[start] + people[end] <= limit) {
            start++; end--;
            answer++;
        }
        else {
            end--;
            answer++;
        }
        if (start == end)
            answer++;
    }
    return answer;
}