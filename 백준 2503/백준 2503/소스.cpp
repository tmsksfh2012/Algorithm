#include <iostream>
using namespace std;

int num[1001];

int chk(int origin, int number, int strike, int ball) {
	int n1 = number / 100, n2 = (number % 100) / 10, n3 = (number % 100) % 10;
	int o1 = origin / 100, o2 = (origin % 100) / 10, o3 = (origin % 100) % 10;
	int stCnt = 0;
	int bCnt = 0;

	if (o1 == 0 || o2 == 0 || o3 == 0 || o1 == o2 || o2 == o3 || o3 == o1)
		return 0;

	if (n1 == o1) { stCnt++; }
	if (n2 == o2) { stCnt++; }
	if (n3 == o3) { stCnt++; }

	if (o1 == n2 || o1 == n3) { bCnt++; }
	if (o2 == n1 || o2 == n3) { bCnt++; }
	if (o3 == n1 || o3 == n2) { bCnt++; }

	if (stCnt == strike && ball == bCnt)
		return 1;
	return 0;
}

int main() {
	int n, ret = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int q, b, s;
		cin >> q >> s >> b;

		for (int i = 123; i <= 987; i++) {
			if (num[i] == 0) {
				num[i] = !chk(i, q, s, b);
			}
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (num[i] == 0) {
			ret++;
		}
	}
	cout << ret << '\n';
	return 0;
}
