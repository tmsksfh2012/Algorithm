#include <iostream>
#include <map>
#include <string>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int TC{};

	__init();

	cin >> TC;

	while (TC--) {
		int N{}, ans = 1;
		map<string, int> m;

		cin >> N;

		while (N--) {
			string product;
			string key;

			cin >> product >> key;

			if (m.find(key) == m.end())
				m.insert({ key, 1 });
			else
				m[key]++;
		}

		for (auto item : m) {
			ans *= item.second + 1;
		}
		cout << ans - 1 << endl;
	}
}