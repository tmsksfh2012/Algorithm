#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str{};
int R{};
vector<int> primeNum{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool bigIntegerDivide(int p);

bool eratostenes(int k) {
	for(int i = 2; i < k; i++) {
		bool isPrime = true;
		if (i != 2 && i % 2 == 0)
			continue;
		for (int j = 3; j * j <= i; j += 2) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			//primeNum.emplace_back(i);
			if (bigIntegerDivide(i))
				continue;
			else {
				R = i;
				return false;
			}
	}
	return true;
}

bool bigIntegerDivide(int p) {

	int sum{};
	for (auto digit : str) {
		sum = (sum * 10 + (digit - '0')) % p;
	}

	if (sum == 0)
		return false;
	else
		return true;
}

int main() {
	__init();

	int k{};

	cin >> str >> k;

	if (eratostenes(k))
		cout << "GOOD";
	else
		cout << "BAD " << R;
}