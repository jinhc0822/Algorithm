#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

/*2022.02.03
적당한 컨테이너만 사용한다면 쉬움.*/

struct INFO {
	string t;
	int res = 0;
	bool in = false;
};

int timeToInt(string t) {
	int res = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
	return res;
}
vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<string, INFO> cars;
	set<string> carName;
	for (int i = 0; i < records.size(); i++) {
		stringstream ss(records[i]);
		string t;
		vector<string> v;
		while (getline(ss, t, ' '))
			v.push_back(t);
		carName.insert(v[1]);
		if (v[2] == "IN") {
			cars[v[1]].t = v[0];
			cars[v[1]].in = true;
		}
		else {
			cars[v[1]].res += (timeToInt(v[0]) - timeToInt(cars[v[1]].t));
			cars[v[1]].in = false;
		}
	}
	for (string s : carName) {
		if (cars[s].in)
			cars[s].res += (timeToInt("23:59") - timeToInt(cars[s].t));
		int fee = fees[1];
		int accT = cars[s].res;
		if (accT > fees[0]) {
			int add = accT - fees[0];
			int tmp = (add % fees[2] != 0) ? add / fees[2] + 1 : add / fees[2];
			fee += tmp * fees[3];
		}
		answer.push_back(fee);
	}
	return answer;
}