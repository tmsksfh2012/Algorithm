#include <iostream>
using namespace std;

int N{};

int main() {
	cin >> N;

	if (N < 10)
		cout << N;

	else {
		int ans{};

		for (int i = 1; i <= N; i*=10) {
			ans += N - i + 1;
		}
		cout << ans;
	}
}