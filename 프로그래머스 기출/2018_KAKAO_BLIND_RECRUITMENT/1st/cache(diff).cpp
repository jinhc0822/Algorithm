#include <string>
#include <vector>
#include <list>
using namespace std;

/*2022.01.24
그냥 단순 검색으로 풀리는구나..
캐시와 캐시 교체 알고리즘에 대한 이해가 부족해서 좀 찾아봤다.
캐시에 빈 곳이 있고 이미 캐시에 CACHE HIT 상황일 때 캐시를 최근에 사용한 것으로 바꿔야 함을 몰랐다.
캐시 교체 알고리즘은 LRU, LFU 등등 알아두는 게 좋겠다. 
카카오 코딩테스트는 기본 알고리즘과 컴퓨터 구조에 대해서 알고 있는 것을 전제로 하기 때문에 사전 설명이 없는 것 같다.*/

list<string> lst;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int sz = 0;
	if (cacheSize == 0)
		return cities.size() * 5;
	for (int i = 0; i < cities.size(); i++)
		for (int j = 0; j < cities[i].size(); j++)
			if (cities[i][j] >= 'a')
				cities[i][j] = cities[i][j] - 32;
	for (int i = 0; i < cities.size(); i++) {
		string city = cities[i];
		bool chk = false;
		for (auto iter = lst.begin(); iter != lst.end(); iter++) {
			if (*iter == city) {
				chk = true;
				answer++;
				lst.erase(iter);
				lst.push_back(*iter);
				break;
			}
		}
		if (!chk) {
			answer += 5;
			if (lst.size() == cacheSize) {
				lst.pop_front();
				lst.push_back(city);
			}
			else
				lst.push_back(city);
		}
	}
	return answer;
}