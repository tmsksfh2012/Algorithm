#include <cstdio>
using namespace std;

int T, t, n;
int dp[2][100002] = { 0, };

int Max(int a, int b) { return a > b ? a : b; }

int main() {
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) for (int j = 2; j < n + 2; j++) scanf("%d", &dp[i][j]);

		for (int j = 2; j < n + 2; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 1) dp[i][j] += Max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
				else dp[i][j] += Max(dp[i + 1][j - 1], dp[i + 1][j - 2]);
			}
		}
		printf("%d\n", Max(dp[0][n + 1], dp[1][n + 1]));
	}

	return 0;
}