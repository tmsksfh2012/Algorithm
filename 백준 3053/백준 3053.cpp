#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int R;

	__init();

	cin >> R;
	cout << fixed;
	cout.precision(6);
	cout << R * R * M_PI << "\n";
	cout<< (2 * R) * (2 * R) / 2 * 1.0;
}