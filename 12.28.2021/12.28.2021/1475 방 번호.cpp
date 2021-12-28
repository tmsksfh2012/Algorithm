#include <iostream>
#include <string>
#include <vector>

using namespace std;
int num_arr[10] = {};
int ans{};
string N{};

void f() {
	for (auto num : N) {
		if (num == '6' || num == '9') {
			num_arr[6] > num_arr[9] ? num_arr[9]++ : num_arr[6]++;
		}
		else {
			num_arr[num - '0']++;
		}
	}
}

int main() {
	cin >> N;

	f();

	for (auto cnt : num_arr)
		ans = ans < cnt ? (cnt > 0 ? cnt : ans) : ans;

	cout << ans;
}