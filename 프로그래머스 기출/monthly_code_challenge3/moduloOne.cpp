#include <vector>
using namespace std;

/*2022.03.01*/

int solution(int n) {
	for (int i = 2; i < n; i++)
		if (n % i == 1)
			return i;
}