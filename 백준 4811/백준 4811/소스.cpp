#include <iostream>
using namespace std;

int N;
long long dp[31][31];

long long dpFc(int N, int day) {

	if (N < 0) return 0;
	if (N == 0 && day == 0) return 1;
	if (dp[N][day]) return dp[N][day];

	if (N > 0) dp[N][day] += dpFc(N - 1, day + 1);
	if (day > 0) dp[N][day] += dpFc(N, day - 1);

	return dp[N][day];
}

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;
		cout << dpFc(N, 0) << "\n";
	}
}