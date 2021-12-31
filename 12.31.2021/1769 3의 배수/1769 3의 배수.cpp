#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

void f(string str, int cnt) {
	if (str.size() < 2) {
		cout << cnt << endl;
		if (stoi(str) % 3 == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	else {
		int sum{};
		for (auto num : str) {
			sum += (num - '0');
		}
		f(to_string(sum), cnt + 1);
	}
}

int main() {
	__init();

	string num{};

	cin >> num;
	f(num, 0);
}