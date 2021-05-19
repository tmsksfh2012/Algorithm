#include <iostream>
#include <cstdio>
using namespace std;

int T;
int dp[31][31];

int combination(int n, int r) {
	if (n == r || r == 0) return 1;
	if (dp[n][r]) return dp[n][r];
	else return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}


int main() {
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		printf("%d\n", combination(b, a));
	}
}