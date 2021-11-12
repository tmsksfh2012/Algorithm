#include <iostream>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int fir, sec, thr;

	__init();

	cin >> fir >> sec >> thr;

	thr -= sec;
	if (thr <= 0) {
		cout << -1;
		return 0;
	}
	cout << fir / thr + 1;
}