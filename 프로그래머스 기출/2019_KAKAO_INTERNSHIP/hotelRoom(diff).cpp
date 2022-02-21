#include <vector>
#include <map>
using namespace std;

/*2022.02.21
union find까지 생각해냈고 풀이 방식에 대해서도 생각해냈는데
왜 못 풀었을까... 근데 계속 효율성 틀리길래 다른 풀이들을 봤는데 내거랑 똑같은데????
이거 진짜 왜 통과 안됨?... 다른 사람 풀이랑 다를게 없는데;;*/

map<long long, long long> r;

long long find(long long u) {
	if (r[u] == 0) return u;
	return r[u] = find(r[u]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (int i = 0; i < room_number.size(); i++) {
		long long n = find(room_number[i]);
		answer.push_back(n);
		r[n] = n + 1;
	}
	return answer;
}