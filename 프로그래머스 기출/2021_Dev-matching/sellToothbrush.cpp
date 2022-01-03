#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/*2022.01.03
ù��° ��� : �Ǹ� ����� ���� �θ� ��尡 ���� ������ ��� ���� �ö󰡸鼭 ����ϴ� ���. ������ ���ð� �� ����̶� �Ȱ���
              ������ 3�� �׽�Ʈ ���̽� �ð� �ʰ�.
�ι�° ��� : ���� �󸶳� �ȾҴ��� �Ѳ����� ���͹迭�� �����س���, enroll���� idx�� Ŭ ���� �Ƕ�̵� �ؿ� �����Ƿ� idx ū �ͺ���
              �� ���� ����ؼ� ���� �Ѳ����� �÷��ִ� ���. ���������� ����°, ù��° �׽�Ʈ ���̽� �ð� �ʰ�.
����° ��� : ��� ���� ��� �� �� ����Ǵ� �ſ��µ� ���� �÷��ִ� 10%�� ���� 0���ӿ��� ��� for���� ���� ������ �ð� �ʰ��� �ɸ� ���̾���...
              e�� 0�� �� �� �̻� �������� �ʰ� �� ��� �ð� �ʰ��� �ɸ��� �ʴ´�. �� ������ ���߳� ��..*/

vector<int> earn[100000];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int sz = enroll.size();
    answer.resize(sz);
    map<string, int> mp;
    for (int i = 0; i < sz; i++)
        mp.insert({ enroll[i], i });
    mp.insert({ "-", -1 });
    for (int i = 0; i < seller.size(); i++) {
        int cur = mp[seller[i]];
        earn[cur].push_back(amount[i] * 100);
    }
    for (int i = sz - 1; i >= 0; i--) {
        if (earn[i].empty())
            continue;
        int next = mp[referral[i]];
        for (int j = 0; j < earn[i].size(); j++) {
            int e = (int)floor(earn[i][j] / 10.0);
            answer[i] += earn[i][j] - e;
            if (next != -1 && e != 0) earn[next].push_back(e);
        }
    }
    return answer;
}