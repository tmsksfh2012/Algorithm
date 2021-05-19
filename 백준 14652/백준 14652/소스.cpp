#include <iostream>
using namespace std;

int main() {
	int col, row, num;
	int ans = 0;

	cin >> col >> row >> num;

	while (num / row) {
		num -= row;
		ans++;
	}

	cout << ans << " " << num;
}