#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500000] = {};

int main() {
	int N, M;

	scanf("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arr[i] = tmp;
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		printf("%d ", tmp == *lower_bound(arr, arr + N, tmp) ? 1 : 0);
	}
}