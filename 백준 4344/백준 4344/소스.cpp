#include <iostream>
using namespace std;

int N, num, sum;
double percent;
int Mat[1000];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		sum = 0;
		percent = 0;
		for (int j = 0; j < num; j++) {
			cin >> Mat[j];
			sum += Mat[j];
		}
		sum /= num;

		for (int o = 0; o < num; o++) {
			if (Mat[o] > sum) {
				percent++;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << percent * 100 / num << "%\n";
	}
}