#include <iostream>
using namespace std;

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	if ((C - B) <= 0) {
		cout << -1;
		return 0;
	}
	else {
		int gap = C - B;
		cout << A / gap + 1;
	}
}