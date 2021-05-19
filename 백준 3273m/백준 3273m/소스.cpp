#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	const int MAX = 100000;
	int arr[MAX];
	int N;
	int X;
	int cnt = 0;


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	scanf("%d", &X);

	int left = 0;
	int right = N;

	for (int i = 0; i < N / 2; i++) {
		left = i;
		int mid = (left + right) / 2;
		int tmp_left = left;
		int tmp_right = right;

		while (true) {
			int tmp_mid = mid;
			if (arr[left] + arr[mid] == X) {
				cnt++;
				break;
			}
			else if (arr[left] + arr[mid] < X) {
				tmp_left = mid;
			}
			else if (arr[left] + arr[mid] > X) {
				tmp_right = mid;
			}
			mid = (tmp_left + tmp_right) / 2;
			if (mid == tmp_mid) break;
		}
	}
	printf("%d", cnt);
}