#include <cstdio>
using namespace std;
int dpMat[1001];
int n;

int dp(int n) {
	dpMat[1] = 1;
	dpMat[2] = 2;
	for (int i = 3; i <= n; i++) dpMat[i] = (dpMat[i - 1] + dpMat[i - 2]) % 10007;
	return dpMat[n];
}

int main() {
	scanf("%d", &n);
	printf("%d\n", dp(n));
	return 0;
}