#include <iostream>
using namespace std;

int N, tot;

int main() {
	cin >> N;

	int tmp;
	while (--N) {
		cin >> tmp;
		tot += --tmp;
	}
	cin >> tmp;
	tot += tmp;

	cout << tot;
}