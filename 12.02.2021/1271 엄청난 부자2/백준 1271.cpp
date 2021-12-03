#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int divide(int fir, int sec) {

}

int digit(int num) {

}

int main() {
	__init();
	string n, m, quotient, reminder;

	cin >> n >> m;

	for (int i{}; i < n.size(); i++) {
		for (int j{}; j < m.size(); j++) {
			if (n[i] < m[i]) {
				n[i - 1]--;
				n[i]++;
			}
		}
	}
}