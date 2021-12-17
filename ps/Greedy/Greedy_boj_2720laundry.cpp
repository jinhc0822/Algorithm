#include <iostream>
using namespace std;

/*2021.12.17
매우 쉬움*/

int t, change;
int coin[4] = { 25, 10, 5, 1 };

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> change;
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            while (coin[i] * cnt <= change)
                cnt++;
            cout << --cnt << ' ';
            change -= coin[i] * cnt;
        }
        cout << '\n';
    }
}