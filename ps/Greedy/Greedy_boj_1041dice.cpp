#include <iostream>
using namespace std;

/*2021.12.17
크게 어렵지는 않았다. 마지막 세 면의 수의 합 구할 때 약간
착오가 있어서 틀림..*/

int n, dice[6], minNum = 51;
long long ans;
int opposite[6] = { 5, 4, 3, 2, 1, 0 };

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
        if (minNum > dice[i])
            minNum = dice[i];
    }
    int maxNum = 0;
    // n이 1일 때
    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            ans += dice[i];
            if (maxNum < dice[i])
                maxNum = dice[i];
        }
        ans -= maxNum;
        cout << ans;
        return 0;
    }
    // 한 면밖에 나오지 않는 주사위의 개수는 (5n-6)(n-2)개이다.
    long long tmp = (5 * n - 6);
    long long tmp2 = (n - 2);
    ans += tmp * tmp2 * minNum;
    // 두 면이 나오는 주사위의 개수는 (n-2)*8+4개이다.
    // 서로 맞닿아 있는 면의 수의 합의 최솟값 구하기
    int m = 1000;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (j == opposite[i])
                continue;
            if (m > dice[i] + dice[j])
                m = dice[i] + dice[j];
        }
    }
    ans += ((n - 2) * 8 + 4) * m;
    // 세 면이 나오는 주사위의 개수는 4개이다.
    m = 1000;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (j == opposite[i])
                continue;
            for (int k = j + 1; k < 6; k++) {
                if (k == opposite[i] || k == opposite[j])
                    continue;
                if (m > dice[i] + dice[j] + dice[k])
                    m = dice[i] + dice[j] + dice[k];
            }
        }
    }
    ans += 4 * m;
    cout << ans;
}