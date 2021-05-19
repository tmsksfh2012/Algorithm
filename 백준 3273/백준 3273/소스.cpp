#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int arr[MAX];

int main() {

	int N, X;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	scanf("%d", &X);

	sort(arr, arr + N);

	int result = 0;

	for (int i = 0; i < N; i++) {

		int low = 0, high = N - 1;

		while (low <= high) {

			int mid = (low + high) / 2;

			if (arr[mid] == X - arr[i]) {
				result++;
				break;
			}
			else if (arr[mid] < X - arr[i])	low = mid + 1;

			else high = mid - 1;
		}
	}

	//이 부분이 핵심

	cout << result / 2 << "\n";

	return 0;
}