#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arrA;
vector<int> arrB;
int ans;

int main() {
	int N;

	scanf("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arrA.emplace_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arrB.emplace_back(tmp);
	}
	sort(arrA.begin(), arrA.end());
	sort(arrB.begin(), arrB.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		ans += arrA[i] * arrB[i];
	}

	printf("%d", ans);
}