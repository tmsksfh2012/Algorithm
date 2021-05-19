#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int money[100001];

bool takeMoney(int mid) {
	int num = 1;
	int sum = mid;

	for (int i = 0; i < N; i++) {
		if (mid < money[i]) return false;

		if (sum - money[i] < 0) {
			sum = mid;
			num++;
		}
		sum -= money[i];
	}
	return M >= num;
}

int main() {
	cin >> N >> M;

	int hi = 0;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		hi = max(hi, money[i]);
	}
	
	int result = 0;
	int lo = hi;
	hi *= N;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (takeMoney(mid)) {
			result = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << result;
}