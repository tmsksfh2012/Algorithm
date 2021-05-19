#include <iostream>
using namespace std;

int main() {
	int N, res;

	cin >> N;
	if (N < 8) cout << 2;
	else {
		N -= 2;
		N /= 6;
		cout << N + 2;
	}
}