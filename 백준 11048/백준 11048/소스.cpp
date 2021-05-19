#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<int>> dp(N, vector<int>(M + 1, 0));

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}

	int cy = 0, cx = 0;
	dp[0][0] = map[0][0];

	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int total = map[i][j];
			
			if (i == 0) {
				if (j == 0) continue;
				total += dp[i][j - 1];
			}
			else if (j == 0) {
				total += dp[i - 1][j];
			}

			else {
				total += max(dp[i - 1][j], dp[i][j - 1]);
			}

			dp[i][j] = total;
		}

	cout << dp[N - 1][M - 1];
}