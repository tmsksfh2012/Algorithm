#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> vc{};
	int N{};
	long long find{};

	cin >> N;

	while (N--) {
		long long tmp{};

		cin >> tmp;
		vc.push_back(tmp);
	}

	cin >> find;

	for (auto num : vc) {
		if (num == find) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}