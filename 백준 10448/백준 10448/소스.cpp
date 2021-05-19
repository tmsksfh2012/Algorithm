#include <iostream>
using namespace std;

int N, num;
int Mat[46];

bool triangleSum(int total) {

	for (int i = 0; i < 46; i++){
		for (int j = 0; j < 46; j++){
			for (int k = 0; k < 46; k++){
				if (Mat[i] + Mat[j] + Mat[k] == total) {
					return true;
				}
			}
		}
	}

	return false;

}

int main() {
	cin >> N;

	for (int i = 0; i < 46; i++) {
		num = (i + 1) * (i + 2) / 2;
		Mat[i] = num;
	}

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		cout << triangleSum(tmp) << endl;
	}
}