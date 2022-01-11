#include <iostream>
using namespace std;

int n{};
int dp[10001]{};
int arr[10001]{};
bool visit[10001]{};

void DP() {
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] > dp[i - 2] + arr[i]) ?
			(dp[i - 1] > dp[i - 3] + arr[i - 1] + arr[i] ?	dp[i - 1] : dp[i - 3] + arr[i - 1] + arr[i]) :
			(dp[i - 2] + arr[i] > dp[i - 3] + arr[i - 1] + arr[i] ?	dp[i - 2] + arr[i] : dp[i - 3] + arr[i - 1] + arr[i]);
	}
}

int main() {
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	DP();
	cout << dp[n];
}