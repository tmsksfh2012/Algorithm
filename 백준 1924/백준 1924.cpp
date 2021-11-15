#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int M, D;
	int type1 = 31, type2 = 30;

	__init();

	cin >> M >> D;

	D--;

	while (M) {
		if (M == 1) break;
		else if (M == 3) D += 28;
		else if (M % 2 == 0 && M <= 8) D += 31;
		else if (M % 2 == 1 && M < 8) D += 30;
		else if (M % 2 == 0 && M > 8) D += 30;
		else if (M % 2 == 1 && M > 8) D += 31;
		M--;
	}
	switch (D % 7) {
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
	}
}