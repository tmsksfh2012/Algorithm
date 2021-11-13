#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int T;
	int cnt_a{}, cnt_b{}, cnt_c{};

	__init();

	cin >> T;

	if (T / 300 > 0) {
		cnt_a = T / 300;
		T %= 300;
	}
	if (T / 60 > 0) {
		cnt_b = T / 60;
		T %= 60;
	}
	if (T / 10 > 0) {
		cnt_c = T / 10;
		T %= 10;
	}

	if (T != 0) cout << -1;
	else cout << cnt_a << " " << cnt_b << " " << cnt_c;
}