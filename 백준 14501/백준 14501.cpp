#include <iostream>
#include <algorithm>
using namespace std;

int N, MAX{};
int arrT[30];
int arrP[30];
int dp[30]{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void calMaxMoney(int num) {
	MAX = MAX > dp[num] ? MAX : dp[num];
	dp[num + arrT[num]] = max(MAX + arrP[num], dp[num + arrT[num]]);
}

int main() {
	
	__init();

	cin >> N;

	for (int i{}; i < N; i++) {
		cin >> arrT[i] >> arrP[i];
	}

	for (int i{}; i <= N; i++)
		calMaxMoney(i);

	cout << dp[N];
}