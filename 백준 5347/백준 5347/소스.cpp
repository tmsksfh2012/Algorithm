#include <iostream>
using namespace std;

int N;
long long a, b;
long long ans;

long long gcd(long long a, long long b) {
	int num = a % b;
	if (num == 0) return a;
	int mod = b % num;

	while (mod != 0) {
		int tmp = mod;
		mod = num % mod;
		num = tmp;
	}

	return num;
}

int main() {
	cin >> N;

	while (N--) {
		cin >> a >> b;
		long long gcdNum = gcd(a, b);
		ans = a * b / gcdNum;
		cout << ans << endl;
	}
}