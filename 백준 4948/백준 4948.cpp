#include <iostream>
using namespace std;

bool IsPrime(int num) {
	for (int j = 3; j * j <= num; j += 2) {
		if (num % j == 0) return false;
	}
	return true;
}

int main() {
	int num;

	while (cin >> num) {
		if (num == 0) return 0;
		int cnt = 0;
		for (int i = num + 1; i <= 2*num; i++) {
			if (i == 2) cnt++;
			else {
				if (i % 2 == 0) continue;
				else {
					if (IsPrime(i)) cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}