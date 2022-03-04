#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*2022.03.02
아니 풀이방법은 솔직히 정해져 있는데 뭔가 자료형에서 틀린 것 같은데...
조금 식을 다르게 해야겠다.. 이런 수학 문제에서는 가능하면 나누기를 안 쓰는게 좋다..*/

bool v[1001][1001];

vector<string> solution(vector<vector<int>> line) {
	vector<string> answer;
	vector<pair<long long, long long>> stars;
	long long minY = LLONG_MAX, minX = LLONG_MAX;
	long long maxY = LLONG_MIN, maxX = LLONG_MIN;
	for (int i = 0; i < line.size() - 1; i++) {
		for (int j = i + 1; j < line.size(); j++) {
			long long m = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
			if (m == 0) continue;
			long long n = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
			long long p = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
			if ((n % m != 0) || (p % m != 0)) continue;
			n /= m;
			p /= m;
			stars.push_back({ n, p });
			if (n > maxX) maxX = n;
			if (n < minX) minX = n;
			if (p > maxY) maxY = p;
			if (p < minY) minY = p;
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