#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*2022.02.03
굳이 done을 만들필요 없이 36번째 줄에서 다시 id map을 사용하는게 나았을것 같다. */

bool done[1000][1000];
int mail[1000];

vector<int>solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	map<string, int> id;
	int n = id_list.size();
	for (int i = 0; i < n; i++)
		id.insert({ id_list[i], i });
	for (string s : report) {
		stringstream ss(s);
		string t;
		vector<string> v;
		while (getline(ss, t, ' ')) {
			v.push_back(t);
		}
		bool& chk = done[id[v[0]]][id[v[1]]];
		if (!chk) {
			mail[id[v[1]]]++;
			chk = true;
		}
	}
	answer.resize(n);
	for (int i = 0; i < n; i++)
		if (mail[i] >= k) {
			for (int j = 0; j < n; j++)
				if (done[j][i])
					answer[j]++;
		}
	return answer;
}