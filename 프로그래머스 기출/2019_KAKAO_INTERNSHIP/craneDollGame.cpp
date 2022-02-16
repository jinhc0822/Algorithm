#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/*2022.02.16*/

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st, b[31];
	int sz = board.size();
	for (int i = 0; i < sz; i++) {
		for (int j = sz - 1; j >= 0; j--) {
			if (board[j][i] == 0) break;
			b[i + 1].push(board[j][i]);
		}
	}
	for (int m : moves) {
		if (b[m].empty()) continue;
		int crane = b[m].top();
		b[m].pop();
		if (st.empty()) {
			st.push(crane);
			continue;
		}
		int basket = st.top();
		if (crane == basket) {
			answer += 2;
			st.pop();
		}
		else
			st.push(crane);
	}
	return answer;
}

int main() {
	int k = solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} },
		{ 1, 5, 3, 5, 1, 2, 1, 4 });
}