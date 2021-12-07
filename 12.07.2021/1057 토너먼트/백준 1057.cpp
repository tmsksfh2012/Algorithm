#include <iostream>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	int N{}, fir{}, sec{}, cnt{};

	cin >> N >> fir >> sec;

	while (++cnt) {
		if (fir % 2 == 1)
			fir = fir / 2 + 1;
		else
			fir /= 2;
		if (sec % 2 == 1)
			sec = sec / 2 + 1;
		else
			sec /= 2;

		if (fir == sec) {
			cout << cnt;
			break;
		}
	}
}