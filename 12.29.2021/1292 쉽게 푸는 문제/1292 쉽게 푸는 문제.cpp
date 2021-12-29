#include <iostream>
using namespace std;

int A{}, B{}, ans{}; int num[1001]{};

int main() {
	cin >> A >> B;

	int cnt{};
	for (int i = 1; i <= 45; i++) {
		for (int j = 1; j <= i; j++) {
			if (cnt + j > 1000)
				break;
			num[cnt + j] = i;
		}
		cnt+=i;
	}

	for (int i = A; i <= B; i++)
		ans += num[i];

	cout << ans;
}