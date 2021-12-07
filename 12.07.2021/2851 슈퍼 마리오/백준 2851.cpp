#include <iostream>
#include <vector>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	__init();
	vector<int> v{};
	int ans{};

	for (int i{}; i < 10; i++) {
		int temp{};
		cin >> temp;
		v.push_back(temp);
	}

	for (auto temp : v) {
		int prev = ans;
		ans += temp;
		int nxt = ans;
		if (ans > 100) {
			ans = 100 - prev >= nxt - 100 ? nxt : prev;
			break;
		}
	}

	cout << ans;
}