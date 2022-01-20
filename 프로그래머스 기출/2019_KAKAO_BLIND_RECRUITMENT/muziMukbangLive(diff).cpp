#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*2022.01.20
후.. 내가 한 코드는 무슨 짓을 해도 효율성 테스트 2번을 뚫지 못했다.. 다른 건 전부 맞는데도.. 
뭐가 문제인지 진짜 모르겠네ㅋㅋ
근데 인터넷에서 본 코드는ㅋㅋ.. 나랑 효율성에서 속도 차이가 엄청 나네ㅋㅋ;;;
구상은 해설과 정확히 맞아떨어졌는데 구현에서 발목이 잡혔다. 굳이 컨테이너를 사용해서 앞의 음식을 
빼려고 할 필요도 없이 index를 이용하면 되었고 while문을 사용할 필요도 없었다.. 남은 음식의 순서를
일일히 셀 필요도 없이 나머지를 이용하면 되는 것이었다. */

struct Food {
	long long left;
	int num;
};

Food food[200001];

bool cmp(Food a, Food b) {
	return a.left < b.left;
}
bool cmp2(Food a, Food b) {
	return a.num < b.num;
}
int solution(vector<int> food_times, long long k) {
	int n = food_times.size();
	for (int i = 0; i < n; i++)
		food[i] = { food_times[i], i + 1 };
	sort(food, food + n, cmp);
	int prevT = 0;
	int tmpN = n;
	for (int i = 0; i < n; i++, tmpN--) {
		long long diff = (long long)(food[i].left - prevT) * tmpN;
		if (diff == 0) continue;
		if (diff <= k) {
			k -= diff;
			prevT = food[i].left;
		}
		else {
			k %= tmpN;
			sort(food + i, food + n, cmp2);
			return food[i + k].num;
		}
	}
	return -1;
}

/*
bool comp(Food a, Food b) {
	if (a.left != b.left)
		return a.left < b.left;
	return a.num < b.num;
}
int solution(vector<int> food_times, long long k) {
	int answer = 0;
	list<Food> food;
	for (int i = 0; i < food_times.size(); i++)
		food.push_back({ food_times[i], i + 1 });
	food.sort(comp);
	long long time = 0;
	long long tmp = 0;
	while (true) {
		long long t = (food.front().left - tmp) * food.size();
		tmp = food.front().left;
		time += t;
		if (time > k) {
			time -= t;
			break;
		}
		if (time == k) {
			while (true) {
				if (food.empty())
					break;
				if (food.front().left - tmp == 1)
					food.front();
				else
					break;
			}
		}
		food.pop_front();
		if (food.empty())
			return -1;
	}
	vector<int> v;
	while (!food.empty()) {
		v.push_back(food.front().num);
		food.pop_front();
	}
	if (v.empty())
		return -1;
	long long t = k - time;
	int idx = 0;
	sort(v.begin(), v.end());
	while (true) {
		if (t == 0) {
			answer = v[idx];
			break;
		}
		idx++;
		if (idx == v.size())
			idx = 0;
		t--;
	}
	return answer;
}*/