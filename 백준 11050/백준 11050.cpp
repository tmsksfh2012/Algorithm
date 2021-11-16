#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N, K;
	int num_top{}, num_bot{};

	__init();

	cin >> N >> K;

	if (K == 0) {
		cout << 1;
		return 0;
	}

	num_top = N;
	num_bot = K;

	for (int i = N - 1; N - i < K; i--) {
		num_top *= i;
	}

	for (int i = K - 1; i > 0; i--) {
		num_bot *= i;
	}

	cout << num_top / num_bot;
}