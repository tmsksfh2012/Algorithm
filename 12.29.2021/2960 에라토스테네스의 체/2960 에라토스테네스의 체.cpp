#include <iostream>
using namespace std;

int N{}, K{}, cnt{};
bool chk[1001]{};

int main() {
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		if (chk[i])
			continue;
		int tmp = i;
		for (; tmp <= N; tmp += i) {
			if (chk[tmp])
				continue;
			cnt++;
			chk[tmp] = true;

			if (cnt == K) {
				cout << tmp;
				return 0;
			}
		}
	}
}