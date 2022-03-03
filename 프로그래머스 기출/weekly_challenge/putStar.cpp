#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*2022.03.02
아니 풀이방법은 솔직히 정해져 있는데 뭔가 자료형에서 틀린 것 같은데...
조금 식을 다르게 해야겠다..*/

bool v[1001][1001];

vector<string> solution(vector<vector<int>> line) {
	vector<string> answer;
	vector<pair<long long, long long>> stars;
	long long minY = LLONG_MAX, minX = LLONG_MAX;
	long long maxY = LLONG_MIN, maxX = LLONG_MIN;
	for (int i = 0; i < line.size() - 1; i++) {
		for (int j = i + 1; j < line.size(); j++) {
			double A = line[i][0], B = line[i][1], C = line[i][2];
			double a = line[j][0], b = line[j][1], c = line[j][2];
			long long n = B * c - C * b;
			long long m = A * b - B * a;
			if (m != 0 && n % m == 0) {
				double x = n / m;
				double y = -(A * x / B) - (C / B);
				if (y != round(y))
					continue;
				if (y < minY) minY = y;
				if (y > maxY) maxY = y;
				if (x < minX) minX = x;
				if (x > maxX) maxX = x;
				stars.push_back(make_pair(x, y));
			}
		}
	}
	for (int i = 0; i < stars.size(); i++) {
		stars[i].first = stars[i].first - minX;
		stars[i].second = maxY - stars[i].second;
		v[stars[i].second][stars[i].first] = true;
	}
	for (int i = 0; i < maxY - minY + 1; i++) {
		string s = "";
		for (int j = 0; j < maxX - minX + 1; j++) {
			if (!v[i][j]) s += '.';
			else s += '*';
		}
		answer.push_back(s);
	}
	return answer;
}
int main() {
	solution({ {2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12} });
}