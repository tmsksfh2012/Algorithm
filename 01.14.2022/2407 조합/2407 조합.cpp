#include <iostream>
using namespace std;

int N{}, M{};
long long dp[101][101]{};
long long dp2[101][101]{};

void combination(int n, int r) {
	for (int i = 0; i <= 100; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp2[i][j] = dp2[i - 1][j - 1] + dp2[i - 1][j];

			if (dp[i][j] >= 10000000000000000) {
				dp2[i][j] += dp[i][j] / 10000000000000000;
				dp[i][j] %= 10000000000000000;
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> M;

	if (N / 2 < M)
		M = N - M;

	combination(N, M);

	if (dp2[N][M] != 0)
		cout << dp2[N][M] << dp[N][M];
	else
		cout << dp[N][M];
}