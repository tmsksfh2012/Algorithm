#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans;

int main() {
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	do {
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			temp += abs(v[i] - v[i + 1]);
		}
		ans = max(ans, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
}