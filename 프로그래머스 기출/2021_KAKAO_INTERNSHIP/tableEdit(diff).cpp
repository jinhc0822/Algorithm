#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

/*2022.02.10
연결리스트를 구현해서 푸는 풀이와 set을 이용하는 풀이가 있다.
연결리스트를 구현하는 풀이는 코드가 길고 조금 복잡할 수 있지만 실행속도가 빠르고
set을 이용한 풀이는 코드는 간결하지만 실행속도가 느리다. 하지만 이 문제의 효율성 테스트를
통과할 정도는 되기에 후자가 더 적합한 풀이인 것 같다.
처음에는 list를 사용하려고 했지만 표를 복원하는 과정에서 약간의 번거로움이 있엇다.
그래서 인터넷을 잠깐 찾아봤는데 애초에 iterator을 사용할 필요가 없이 어차피 표는
오름차순 정렬이 되어야하기 때문에 자동정렬을 지원하는 set이 더 낫다는 글을 보았다.
표가 무조건 오름차순이어야하기 때문에 이를 이용하는 것만 깨달았으면 훨씬 빠르게
풀었을 것 같다.*/

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');
	set<int> table;
	stack<int> erased;
	for (int i = 0; i < n; i++)
		table.insert(i);
	set<int>::iterator iter = table.begin();
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
			erased.push(*iter);
			iter = table.erase(iter);
			if (iter == table.end())
				iter--;
		}
		else {
			table.insert(erased.top());
			erased.pop();
		}
	}
	for (auto i : table)
		answer[i] = 'O';
	return answer;
}