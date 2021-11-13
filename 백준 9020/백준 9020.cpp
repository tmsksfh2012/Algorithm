#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool compare (pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

bool isPrime(int num) {
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	else {
		for (int i = 3; i * i <= num; i += 2)
			if (num % i == 0) return false;

		return true;
	}
}

int main() {
	int tc;

	__init();

	cin >> tc;

	while (tc--) {
		int num;
		vector<pair<int, int>> v;

		cin >> num;

		for (int i = 2; 2 * i <= num; i++) {
			if (isPrime(i) && isPrime(num - i)) {
				v.push_back({ i, num - 2 * i });
			}
		}
		sort(v.begin(), v.end(), compare);

		cout << v[0].first << " " << num - v[0].first << "\n";
	}
}