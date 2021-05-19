#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MIN;
int N, K;
vector<int> s;
int ans;

int main() {
	cin >> N >> K;

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}

	// 	min(s[0], s[K-1]);

	while (true) {
		ans++;
		N = N - K + 1;
		if (N > K) continue;
		else {
			ans++;
			break;
		}
	}
	cout << ans;
}