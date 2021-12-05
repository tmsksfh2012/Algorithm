#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{};

	__init();

	cin >> N;

	if (N % 2 > 0)
		cout << "Either";
	else {
		cout << "Odd";
	}
}