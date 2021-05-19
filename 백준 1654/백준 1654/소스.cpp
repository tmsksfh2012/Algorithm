#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int Mat[10001];

bool chk(int mid) {
	int cnt = 0;
	for (int i = 0; i < K; ++i)
		cnt += Mat[i] / mid;

	return cnt >= N;
}

int main() {
	cin >> K >> N;

	int max = 0;

	for (int i = 0; i < K; i++) {
		cin >> Mat[i];
		max = max > Mat[i] ? max : Mat[i];
	}

	long long left = 1, right = max, ans = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (chk(mid)) {
			if (mid > ans)
				ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans;
}