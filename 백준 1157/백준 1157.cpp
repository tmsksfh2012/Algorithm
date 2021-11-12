#include <iostream>
#include <string>
using namespace std;

int alpha[27];

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	string str;
	int max = 0;
	int num{};

	__init();

	cin >> str;
	for (char ch : str) {
		alpha[toupper(ch)-64]++;
	}
	for (int i{ 1 }; i < 27; i++) {
		if (max && max == alpha[i]) {
			num = (int)'?';
		}
		if (max < alpha[i]) {
			max = alpha[i];
			num = i + 64;
		}
	}
	cout << (char)num;
}
