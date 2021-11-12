#include <iostream>
using namespace std;

int main() {
	string a, b;
	int fir = 0, sec = 0;
	int mult = 1;

	cin >> a >> b;

	for (int i{}; i < a.size(); i++) {
		fir = fir + (a[i] - '0') * mult;
		sec = sec + (b[i] - '0') * mult;
		mult *= 10;
	}
	
	cout << (fir > sec ? fir : sec);
}