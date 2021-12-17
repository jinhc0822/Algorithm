#include <iostream>
using namespace std;

/*2021.12.17
½¬¿ò..*/

int n, m[30000];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    int idx = 0, ans = 0;
    while (idx < n) {
        int k = 1, cnt = 0;
        while (idx + k < n && m[idx] > m[idx + k]) {
            k++;
            cnt++;
        }
        if (ans < cnt)
            ans = cnt;
        idx += k;
    }
    cout << ans;
}