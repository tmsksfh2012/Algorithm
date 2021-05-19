#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int number[10000001];
int a, b, k;

int fd(int now) {
	cout << now << " ";
	if (number[now] == -1) {
		return now;
	}
	else if (number[now] != 0) {
		return number[now];
	}
	else {
		number[now] = -1;
		int ntg = 0;
		for (int i = 1; now / i != 0; i *= 10) {/*SK(now)*/
			int ex = (now % (i * 10)) / i;
			int nex = ex;
			for (int j = 1; j < k; j++) {
				ex *= nex;
			}
			ntg += ex;
		}
		return number[now] = min(now, fd(ntg));
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b >> k;
	long long int value = 0;
	for (int i = a; i <= b; i++) {
		value += fd(i);
		cout << "\n";
	}
	cout << value << "\n";
	return 0;
}