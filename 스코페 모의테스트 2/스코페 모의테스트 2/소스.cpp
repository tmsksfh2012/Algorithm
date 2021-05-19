#include <stdio.h>

int main() {
	int T;
	long long M, N, k1, k2, k;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%lld %lld", &N, &M);

		k1 = N / 5;
		k2 = (N + M) / 12;
		k = k1 < k2 ? k1 : k2;

		printf("%lld\n", k);
	}
	return 0;
}