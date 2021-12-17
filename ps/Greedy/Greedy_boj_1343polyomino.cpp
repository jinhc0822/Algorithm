#include <iostream>
using namespace std;

/*2021.12.17
½¬¿ò.*/

string board, ans;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> board;
    for (int i = 0; i < board.size();) {
        int cnt = 0;
        while (board[i] == 'X') {
            cnt++; i++;
            if (cnt == 4 || i == board.size()) break;
        }
        if (cnt == 4)
            ans += "AAAA";
        else if (cnt == 2)
            ans += "BB";
        else if (cnt == 0) {
            ans += '.';
            i += 1;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}