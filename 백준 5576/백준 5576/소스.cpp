#include<cstdio>
#include<algorithm>

int main() {
	int arr[11];
	for (int t = 0; t < 2; ++t) {
		for (int i = 0; i < 10; ++i) scanf("%d", &arr[i]);
		std::sort(arr, arr + 10);
		printf("%d ", arr[9] + arr[8] + arr[7]);
	}
}