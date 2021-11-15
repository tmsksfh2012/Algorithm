#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int num, cnt, max{};

	__init();

	cin >> num >> cnt;

	for (int i = 1; i <= cnt; i++) {
		int tmp, rev{};
		tmp = num * i;
		while (tmp) {
			rev = 10 * rev + tmp % 10;
			tmp /= 10;
		}
		max = rev > max ? rev : max;
	}
	cout << max;
}