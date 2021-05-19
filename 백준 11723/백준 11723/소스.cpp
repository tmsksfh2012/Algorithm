#include <iostream>
using namespace std;

int N, result, tmp;
string input;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "add") {
			cin >> tmp;
			result |= (1 << tmp);
		}
		else if (input == "check") {
			cin >> tmp;
			if (result & (1 << tmp))    cout << 1 << '\n';
			else    cout << 0 << '\n';
		}
		else if (input == "remove") {
			cin >> tmp;
			result &= ~(1 << tmp);
		}
		else if (input == "toggle") {
			cin >> tmp;
			result ^= (1 << tmp);
		}
		else if (input == "all") {
			result = (1 << 21) - 1;
		}
		else if (input == "empty") {
			result = 0;
		}
	}
}