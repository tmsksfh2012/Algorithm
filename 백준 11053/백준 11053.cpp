#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001]{};
int dp[1001]{};
int N, ans = 0;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void findSequence() {
	for (int i = 1; i <= N; i++) {
		int sec = arr[i];
		for (int j = i - 1; j >= 1; j--) {
			int fir = arr[j];

			if (sec > fir) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
}

int main() {
	__init();

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	
	findSequence();
	cout << ans;
}