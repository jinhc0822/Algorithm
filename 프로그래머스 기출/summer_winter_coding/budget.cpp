#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.01*/

int solution(vector<int> d, int budget) {
	int cnt = 0, sum = 0;
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++) {
		sum += d[i];
		if (sum == budget)
			return i + 1;
		else if (sum > budget)
			return i;
	}
	return d.size();
}