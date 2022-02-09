#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>
using namespace std;

/*2022.02.10*/

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	list<int> lst;
	stack<pair<int, list<int>::iterator>> erased;
	for (int i = 0; i < n; i++)
		lst.push_back(i);
	list<int>::iterator iter = lst.begin();
	for (int i = 0; i < k; i++)
		iter++;

	for (string s : cmd) {
		if (s[0] == 'U') {
			int x = stoi(s.substr(2));
			for (int i = 0; i < x; i++)
				iter--;
		}
		else if (s[0] == 'D') {
			int x = stoi(s.substr(2));
			for (int i = 0; i < x; i++)
				iter++;
		}
		else if (s[0] == 'C') {
			erased.push({ *iter, iter });
			iter = lst.erase(iter);
			if (iter == lst.end())
				iter--;
		}
		else {
			auto iter2 = erased.top().second;
			int idx = erased.top().first;
			erased.pop();
			lst.insert(iter2, idx);
		}
	}
	for (int i = 0; i < n; i++)
		answer += 'X';
	for (auto i : lst)
		answer[i] = 'O';
	return answer;
}

int main() {
	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
}