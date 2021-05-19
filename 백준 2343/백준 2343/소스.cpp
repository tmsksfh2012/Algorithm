#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
int Mat[100001];

int main() {
	cin >> N >> M;

	int Max = 0;

	for (int i = 0; i < N; i++) {
		cin >> Mat[i];
		Max += Mat[i];
	}

	Max /= M;

	while (true) {
		int sum = 0;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			if (sum + Mat[i] > Max) {
				ans = max(ans, sum);
				cnt++;
				sum = Mat[i];
				continue;
			}
			sum += Mat[i];
		}
		ans = max(ans, sum);
		cnt++;
		if (cnt > M) Max++;
		else {
			cout << ans;
			break;
		}
	}
}