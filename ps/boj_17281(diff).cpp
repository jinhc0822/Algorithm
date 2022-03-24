#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*2022.03.24
������ ����Ž��, ������ �´ٰ� �����ؼ� Ǯ���µ� �ð��ʰ� ���Դ�.. �׷��� �з��� �ô��� �з��� ���� ������ 
�״�ο���. hit �Լ����� 4��, �ϳ��� 0�̰� ���� Ȩ���� �� 43��, �̴��� �� �ִ� 50��, 
�׸��� �����ϴ� ������ ���� ��� ���ϸ� 3�� 5õ ������ ������ �Ѵ�... � ������� �ð��� �ٿ����ұ�?
�� �̴��� ����� ���� �ٸ� ���� �ֱ� ������ ������ �ǵ�� ���� �ƴѰ� ������.. �̴� ���� �翬�� �ǵ帱 ���� 
���� ���̰�. ���ھ ���ϴ� ����� �ٲ���� �� ����.
������ �����غ��� �� �̴� ������ ģ Ÿ�� �����ٰ� �̴��� ������ ���� ���� ���� ���� ������ �ƴұ� �ϴ� ������
�� ť�� �ذ��غ��� �����ߴ�.
�ٵ� ���� ť�� ����� ���� �̴� ���� while���� ������ �ʴ� �̻� �ð��� ũ�� �پ���� ���� �� ���ٰ� �����ߴµ�
���ó� 1% �ð��ʰ����� 50% �ð��ʰ���� ���̰� ������ �ð��ʰ��� ����.
�׷��� �ٸ� Ǯ�̵��� �ôµ� �� Ǯ�̶� �ٸ� �͵� ���� �׳� field �����ؼ� ������ �� if������ �ذ��� Ǯ�̵�
����ߴµ� �� �ȵǴ� ����?? �Ȱ��� ���� ���ϴ°� 3�� ���� �ݺ��Ǵµ� �� �� �� �ð��ʰ��� ������ �𸣰ڴ�.
next_permutation�� ��ͷ� ȣ���ϴ� �ͺ��� �ð��� �����ٴµ� ��.. ����..*/

vector<int> order, v = { 2, 3, 4, 5, 6, 7, 8, 9 };
int n, inning[50][10], answer;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 10; j++)
            cin >> inning[i][j];
    do {
        int score = 0;
        order.push_back(0);
        for (int i = 0; i < 9; i++) {
            if (i < 3) order.push_back(v[i]);
            else if (i == 3) order.push_back(1);
            else order.push_back(v[i - 1]);
        }
        int hitter = 1;
        for (int i = 0; i < n; i++) {
            int out = 0, cnt = 0;
            queue<bool> q;
            while (true) {
                int res = inning[i][order[hitter]];
                if (res == 0) out++;
                else {
                    for (int i = 0; i < res; i++) {
                        if (i == 0) q.push(true);
                        else q.push(false);
                        if (q.size() > 3) q.pop();
                    }
                    cnt++;
                }
                hitter++;
                if (hitter == 10)
                    hitter = 1;
                if (out == 3) break;
            }
            int k = 0;
            while (!q.empty()) {
                if (q.front())
                    k++;
                q.pop();
            }
            score += (cnt - k);
        }
        if (answer < score)
            answer = score;
        order.clear();
    } while (next_permutation(v.begin(), v.end()));
    cout << answer;
}