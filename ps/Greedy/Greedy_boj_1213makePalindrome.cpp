#include <iostream>
using namespace std;

/*2021.12.17
좀 길게 쓴거 같긴한데 쉬운 문제. 근데 이게 왜 그리디인지는 모름..*/

string s;
int a[26], idx = -1, cnt;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'A']++;
    for (int i = 0; i < 26; i++)
        if (a[i] % 2) {
            idx = i;
            cnt++;
        }
    string ans;
    if (s.length() % 2 == 0) {
        if (idx != -1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    else {
        if (cnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i == idx) a[i]--;
        a[i] /= 2;
        while (a[i]--) {
            ans += (i + 'A');
        }
    }
    string tmp;
    for (int i = ans.length() - 1; i >= 0; i--)
        tmp += ans[i];
    if (idx != -1)
        ans += idx + 'A';
    cout << ans + tmp;
}