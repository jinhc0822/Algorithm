#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*2022.02.03
사실은 curTime==lastTime일 때랑 아닐 때 굳이 구분해서 할 필요 없이 
간단하게 생각하면 될 일인데 너무 복잡하게 생각한 것 같다. 
콘을 무조건 마지막 셔틀버스에 탑승시킨다고 생각하고, 마지막 셔틀이 꽉 찼을 경우
마지막에 탄 사람보다 1분 일찍 셔틀버스 도착 장소에 도착하게 만들면 될 것이다.
이 방법을 통해 코드를 반이나 줄일 수 있다....*/

int timeToInt(string t) {
	int res = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
	return res;
}
string intToTime(int t) {
	string res = "";
	if (t / 60 < 10)
		res += '0';
	res += to_string(t / 60);
	res += ':';
	if (t % 60 < 10)
		res += '0';
	res += to_string(t % 60);
	return res;
}
string solution(int n, int t, int m, vector<string> timetable) {
	int curTime = 540;
	int lastTime = curTime + t * (n - 1);
	vector<int> crew;
	map<int, int> numberOfCrew;
	for (int i = 0; i < timetable.size(); i++) {
		int t = timeToInt(timetable[i]);
		numberOfCrew[t]++;
		crew.push_back(t);
	}
	sort(crew.begin(), crew.end());
	int idx = 0;
	while (curTime <= lastTime) {
		int curM = 0;
		if (curTime == lastTime) {
			if (idx >= crew.size())
				return intToTime(lastTime);
			while (true) { 
				if (idx >= crew.size() && curM < m)
					return intToTime(lastTime);
				if (crew[idx] > curTime)
					return intToTime(lastTime);
				if (numberOfCrew[crew[idx]] + curM >= m)
					return intToTime(crew[idx] - 1);
				curM += numberOfCrew[crew[idx]];
				idx += numberOfCrew[crew[idx]];
			}
		}
		else {
			while (true) {
				if (idx >= crew.size() || crew[idx] > curTime || curM == m)
					break;
				if (curM < m && crew[idx] <= curTime) {
					if (numberOfCrew[crew[idx]] + curM > m) {
						numberOfCrew[crew[idx]] -= (m - curM);
						idx += (m - curM);
						curM = m;
					}
					else {
						curM += numberOfCrew[crew[idx]];
						idx += numberOfCrew[crew[idx]];
					}
				}
			}
		}
		curTime += t;
	}
}

int main() {
	cout << solution(10, 60, 45, { "23:59" });
}