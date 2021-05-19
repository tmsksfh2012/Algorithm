#include <iostream>
using namespace std;

int main() {
	int N, M;
	int Mat[100001] = { 0, };
	int Res[100001] = { 0, };
	int result = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &Mat[i]);
		result += Mat[i];
		Res[i] = result;
	}

	int x, y;
	for (int j = 0; j < M; j++) {
		scanf("%d", &x);
		scanf("%d", &y);
		printf("%d\n", Res[y] - Res[x - 1]);
	}
}