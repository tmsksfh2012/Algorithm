#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N = 9;
	int Mat[9];
	int sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &Mat[i]);
		sum += Mat[i];
	}

	int tmp = 0;

	bool check = false;
	for (int j = 0; j < N; j++) {
		for (int o = j + 1; o < N; o++) {
			tmp = Mat[j] + Mat[o];
			if ((sum - tmp) == 100) {
				Mat[j] = 0;
				Mat[o] = 0;
				check = true;
			}
		}
		if (check) break;
	}

	sort(Mat, Mat + N);
	for (int p = 0; p < N; p++) {
		if (Mat[p] != 0) {
			printf("%d\n", Mat[p]);
		}
	}

	return 0;
}