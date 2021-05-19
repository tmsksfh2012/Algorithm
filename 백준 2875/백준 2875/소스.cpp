#include <iostream>
using namespace std;

int N, M, K;
int w, m;

int main() {
	cin >> N >> M >> K;

	w = N / 2;
	m = M;

	while (K > 0) {
		if (w >= m) {
			w--;
			K -= 2;
		}
		else {
			m--;
			K--;
		}
	}
	cout << (w > m ? m : w);
}