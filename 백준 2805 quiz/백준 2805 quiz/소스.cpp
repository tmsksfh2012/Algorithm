#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long K;
long long ans;
long long arr[1000000];

bool possible(long long height) {
	long long len = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] - height > 0)
			len += arr[i] - height;
	}
	if (len >= K) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;


	long long start = 1;
	long long mid;
	long long last = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		last = max(last, arr[i]);
	}

	while (start <= last) {
		mid = (start + last) / 2;

		if (possible(mid)) {
			ans = (ans >= mid ? ans : mid);
			start = mid + 1;
		}
		else last = mid - 1;
	}
	cout << ans;
}