#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int R, B, total, side_x{}, side_y{};
	__init();

	cin >> R >> B;

	total = R + B;

	for (int x = 1; 2 * x < R; x++) {
		int delta = R - 2 * x;
		int y = delta / 2 + 2;
		if ((2 * x) + 2 * (y - 2) == R) {
			if (x * y == total) {
				side_x = x;
				side_y = y;
				break;
			}
		}
	}
	cout << side_y << " " << side_x;
}