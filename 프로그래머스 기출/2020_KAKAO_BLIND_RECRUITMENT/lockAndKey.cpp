#include <vector>
using namespace std;

/*2022.01.11
발상이 어려운 문제는 아니었다.*/

int m, n;
vector<vector<int>> Key, Lock;

bool compare(int y, int x) {
    vector<vector<int>> lock;
    lock.assign(Lock.begin(), Lock.end());
    for (int i = y; i < n; i++) {
        if (i - y >= m) 
            break;
        for (int j = x; j < n; j++) {
            if (j - x >= m)
                break;
            if (Key[i - y][j - x] == 1 && lock[i][j] == 1)
                return false;
            else if (lock[i][j] == 0 && Key[i - y][j - x] == 1)
                lock[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (lock[i][j] == 0)
                return false;
    return true;
}
void rotate(vector<vector<int>>& v) {
    vector<int> tmp;
    for (int i = v.size() - 1; i >= 0; i--)
        for (int j = 0; j < v[i].size(); j++)
            tmp.push_back(v[i][j]);
    int idx = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size(); j++)
            v[j][i] = tmp[idx++];
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size();
    n = lock.size();
    Key.assign(key.begin(), key.end());
    Lock.assign(lock.begin(), lock.end());
    for (int r1 = 0; r1 < 4; r1++) {
        for (int r2 = 0; r2 < 4; r2++) {
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    if (compare(i, j))
                        return true;
            rotate(Key);
        }
        rotate(Lock);
    }
    return false;
}