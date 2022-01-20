#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*2022.01.20
��.. ���� �� �ڵ�� ���� ���� �ص� ȿ���� �׽�Ʈ 2���� ���� ���ߴ�.. �ٸ� �� ���� �´µ���.. 
���� �������� ��¥ �𸣰ڳפ���
�ٵ� ���ͳݿ��� �� �ڵ�¤���.. ���� ȿ�������� �ӵ� ���̰� ��û ���פ���;;;
������ �ؼ��� ��Ȯ�� �¾ƶ������µ� �������� �߸��� ������. ���� �����̳ʸ� ����ؼ� ���� ������ 
������ �� �ʿ䵵 ���� index�� �̿��ϸ� �Ǿ��� while���� ����� �ʿ䵵 ������.. ���� ������ ������
������ �� �ʿ䵵 ���� �������� �̿��ϸ� �Ǵ� ���̾���. */

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