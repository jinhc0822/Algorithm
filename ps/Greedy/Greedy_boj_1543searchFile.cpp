#include <iostream>
#include <string>
using namespace std;

/*2021.12.17
완전탐색으로 가능한 문제.*/

string s, pat;
bool match[2500];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    getline(cin, s);
    getline(cin, pat);
    int sLen = s.length(), patLen = pat.length();
    for (int i = 0; i < sLen - patLen + 1; i++) {
        bool chk = true;
        for (int j = 0; j < patLen; j++) {
            if (s[i + j] != pat[j])
                chk = false;
        }
        if (chk)
            match[i] = true;
    }
    int ans = 0;
    for (int i = 0; i < sLen - patLen + 1; ) {
        if (match[i]) {
            ans++;
            i += patLen;
        }
        else
            i++;
    }
    cout << ans;
}