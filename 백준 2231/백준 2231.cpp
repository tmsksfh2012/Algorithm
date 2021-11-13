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

	ans = N;
	
	while (N % 10) {
		ans += N % 10;
		N /= 10;
	}

	cout << ans;
}