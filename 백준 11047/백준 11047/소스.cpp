#include <iostream>
using namespace std;

int main() {
	int N, K;
	int A[10];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int count = 0;
	while (K != 0) {
		for (int i = N - 1; i >= 0; i--) {
			if (K >= A[i]) {
				K -= A[i];
				count++;
				break;
			}
		}
	}
	cout << count << endl;
}