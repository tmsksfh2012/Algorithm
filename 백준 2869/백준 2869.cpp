#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int A, B, V;
	int sum = 0, cnt = 1;
	
	__init();

	cin >> A >> B >> V;
	if ((V - A) % (A - B) == 0) {
		cout << (V - A) / (A - B) + 1;
	}
	else {
		cout << (V - A) / (A - B) + 2;
	}
}