#include <iostream>
using namespace std;

int N{};
double MAX{};
double arr[10001]{};
double dp[10001]{};

void DP() {
	dp[0] = 1;
	dp[1] = arr[1];

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] * arr[i] > arr[i] ? dp[i - 1] * arr[i] : arr[i];
		MAX = MAX < dp[i] ? dp[i] : MAX;
	}

}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	DP();

	cout << fixed;
	cout.precision(3);
	cout << MAX;
}