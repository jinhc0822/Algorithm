#include <vector>
#include <algorithm>
using namespace std;

/*2022.03.02*/

int solution(vector<vector<int>> sizes) {
	int w = 0, h = 0;
	for (int i = 0; i < sizes.size(); i++) {
		w = max(w, max(sizes[i][0], sizes[i][1]));
		h = max(h, min(sizes[i][0], sizes[i][1]));
	}
	return w * h;
}