#include <iostream>
#include <algorithm>
using namespace std;

int H{}, Y{};
int dp[11]{};

bool isValid(int y, int num) {
	return (y - num) >= 0;
}

void DP(int y) {
	if (y > Y)
		return;
	else {
		int one{}, three{}, five{};
		if (isValid(y, 1))
			one = dp[y - 1] * 1.05;
		if (isValid(y, 3))
			three = dp[y - 3] * 1.2;
		if (isValid(y, 5))
			five = dp[y - 5] * 1.35;

		dp[y] = one > three ? (one > five ? one : five) : (three > five ? three : five);
		DP(y + 1);
	}
}

int main() {
	cin >> H >> Y;
	dp[0] = H;
	DP(1);

	cout << dp[Y];
}