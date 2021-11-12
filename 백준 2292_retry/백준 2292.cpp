#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int num;
	int cnt = 1, sum = 1;

	__init();

	cin >> num;

	while (sum < num) {
		sum = sum + (cnt++)*6;
	}
	cout << cnt;
}