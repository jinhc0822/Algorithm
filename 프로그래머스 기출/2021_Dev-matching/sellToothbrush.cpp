#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/*2022.01.03
첫번째 방법 : 판매 기록을 따라 부모 노드가 없을 때까지 계속 위로 올라가면서 계산하는 방식. 문제의 예시가 한 방법이랑 똑같음
              마지막 3개 테스트 케이스 시간 초과.
두번째 방법 : 누가 얼마나 팔았는지 한꺼번에 벡터배열에 저장해놓고, enroll에서 idx가 클 수록 피라미드 밑에 있으므로 idx 큰 것부터
              번 돈을 계산해서 위로 한꺼번에 올려주는 방식. 마지막에서 세번째, 첫번째 테스트 케이스 시간 초과.
세번째 방법 : 사실 앞의 방법 둘 다 통과되는 거였는데 위로 올려주는 10%의 돈이 0원임에도 계속 for문이 돌기 때문에 시간 초과가 걸린 것이었다...
              e가 0일 때 더 이상 진행하지 않게 할 경우 시간 초과가 걸리지 않는다. 이 생각을 못했네 ㅜ..*/

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