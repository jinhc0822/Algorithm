#include <string>
#include <vector>
using namespace std;

/*2022.01.03
copy를 만드는 게 훨씬 쉬운 것 같다. 단순 구현 문제.*/

int arr[101][101], arrCopy[101][101];

int rotate(int x1, int y1, int x2, int y2) {
    int ans = 10001;
    for (int i = y1 + 1; i <= y2; i++) {
        arr[x1][i] = arrCopy[x1][i - 1];
        if (ans > arr[x1][i])
            ans = arr[x1][i];
    }
    for (int i = x1 + 1; i <= x2; i++) {
        arr[i][y2] = arrCopy[i - 1][y2];
        if (ans > arr[i][y2])
            ans = arr[i][y2];
    }
    for (int i = y1; i < y2; i++) {
        arr[x2][i] = arrCopy[x2][i + 1];
        if (ans > arr[x2][i])
            ans = arr[x2][i];
    }
    for (int i = x1; i < x2; i++) {
        arr[i][y1] = arrCopy[i + 1][y1];
        if (ans > arr[i][y1])
            ans = arr[i][y1];
    }
    return ans;
}
void copy(int r, int c) {
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            arrCopy[i][j] = arr[i][j];
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int k = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            arr[i][j] = k++;
    copy(rows, columns);
    for (vector<int> v : queries) {
        int ans = rotate(v[0], v[1], v[2], v[3]);
        copy(rows, columns);
        answer.push_back(ans);
    }
    return answer;
}