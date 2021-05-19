#include <iostream>
#define mod 1000000000
using namespace std;

int N;
long long Dp[101][10] = {};
long long sum = 0;

int main(void) {
	cin >> N;
	Dp[1][0] = 0;
	for (int i = 1; i < 10; i++) Dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				Dp[i][0] = Dp[i - 1][1];
			else if (j == 9)
				Dp[i][9] = Dp[i - 1][8];
			else
				Dp[i][j] = (Dp[i - 1][j - 1] + Dp[i - 1][j + 1]);
		}
	}
	for (int i = 0; i < 10; i++) sum += Dp[N][i] % mod;
	cout << sum % mod;
}
