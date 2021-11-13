#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int arr[10]{};
	int sum{}, fir, sec;

	__init();

	for (int i{}; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i{}; i < 9; i++)
		for (int j = i + 1; j < 9; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				fir = i;
				sec = j;
			}
		}

	for (int i{}; i < 9; i++) {
		if (i == fir || i == sec) continue;
		else cout << arr[i] << "\n";
	}
}