#include <vector>
#include <algorithm>
using namespace std;

/*2021.12.14
�� �����ͷ� �ذ�. ������� �� �¿�� ���� ����� 1���� ��츦 �������� ���ؼ� ���� ��̴�.*/

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