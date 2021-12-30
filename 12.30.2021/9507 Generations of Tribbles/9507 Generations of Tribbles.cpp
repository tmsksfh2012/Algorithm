#include <iostream>
#define N 68
#define endl "\n"
using namespace std;

int TC{};
long long dp[N]{};

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

void DP() {
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 4;

	for (int i = 4; i < N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
}

int main() {
	__init();

	cin >> TC;

	DP();

	while (TC--) {
		int num{};
		cin >> num;

		cout << dp[num] << endl;
	}
}