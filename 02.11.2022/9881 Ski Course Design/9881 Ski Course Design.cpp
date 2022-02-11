#include <stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, hills[1000];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hills[i];

	int ans = 99999999;
	for (int i = 0; i <= 100 - 17; i++) {
		// i ~ i + 17 까지가 우리가 잡은 범위!
		int tempAns = 0;
		for (int j = 0; j < N; j++) {
			if (hills[j] < i) tempAns += (i - hills[j]) * (i - hills[j]);
			if (hills[j] > i + 17) tempAns += (hills[j] - i - 17) * (hills[j] - i - 17);
		}
		ans = min(ans, tempAns);
	}
	cout << ans << '\n';
}