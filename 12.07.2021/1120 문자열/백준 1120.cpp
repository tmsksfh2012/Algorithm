#include <iostream>
#include <string>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	__init();

	string a{}, b{};
	int ans = 987654321;

	cin >> a >> b;

	for (int i{}; i <= b.size() - a.size(); i++) {
		int cnt{};
		for (int j{}; j < a.size(); j++) {
			if (a[j] != b[i + j])
				cnt++;
		}
		ans = ans > cnt ? cnt : ans;
	}

	cout << ans;
}