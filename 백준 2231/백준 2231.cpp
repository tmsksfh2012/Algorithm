#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, ans{};

	__init();

	cin >> N;

	int tmp{};
	for (int i = 1; i < N; i++) {
		tmp = i;
		ans = i;
		while (tmp % 10) {
			ans += tmp % 10;
			tmp /= 10;
		}
		if (ans == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}