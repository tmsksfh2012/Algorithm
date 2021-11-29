#include <iostream>
#include <map>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, M{}, ans{};
	map<int, int> m;
	__init();

	cin >> N >> M;

	int K = N + M;

	while (K--) {
		int tmp{};

		cin >> tmp;

		auto numPair = m.find(tmp);
		if (numPair != m.end()) {
			numPair->second++;
		}
		else
			m.insert({ tmp, 1 });
	}

	for (auto i : m) {
		if (i.second == 1)
			ans++;
	}

	cout << ans;
}