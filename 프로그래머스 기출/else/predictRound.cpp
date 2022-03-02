using namespace std;

/*2022.03.02*/

int solution(int n, int a, int b) {
	int round = 1;
	while (true) {
		if (a % 2 == 1 && b - a == 1)
			return round;
		else if (a % 2 == 0 && a - b == 1)
			return round;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		round++;
	}
}