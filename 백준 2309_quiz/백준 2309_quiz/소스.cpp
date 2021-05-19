#include <iostream>
#include <algorithm>
using namespace std;

int Mat[9];
int N = 9, sum;

int main() {
	for (int i = 0; i < N; i++) {
		cin >> Mat[i];
		sum += Mat[i];
	}
	bool status = false;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sum - (Mat[i] + Mat[j]) == 100) {
				Mat[i] = 0;
				Mat[j] = 0;
				break;
			}
			if (status) break;
		}
	}
	sort(Mat, Mat + N);
	for (int tmp : Mat) {
		if (tmp != 0) {
			cout << tmp << '\n';
		}
	}
}