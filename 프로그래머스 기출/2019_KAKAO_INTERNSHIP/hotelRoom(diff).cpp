#include <vector>
#include <map>
using namespace std;

/*2022.02.21
union find���� �����س°� Ǯ�� ��Ŀ� ���ؼ��� �����س´µ�
�� �� Ǯ������... �ٵ� ��� ȿ���� Ʋ���淡 �ٸ� Ǯ�̵��� �ôµ� ���Ŷ� �Ȱ�����????
�̰� ��¥ �� ��� �ȵ�?... �ٸ� ��� Ǯ�̶� �ٸ��� ���µ�;;*/

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