#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	__init();

	int N{}, K{}, cnt{};

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) cnt++;
		if (cnt == K) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}