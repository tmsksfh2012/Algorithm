#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N{}, K{}, W{}, V{};
int dp[101][100001]{};
// first -> weight, second -> value
vector<pair<int, int>> vc{};

void DP() {
	int idx{};
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (vc[i - 1].first <= w) {
				pair<int, int> item = vc[i - 1];
				if (item.second + dp[i - 1][w - item.first] > dp[i - 1][w])
					dp[i][w] = item.second + dp[i - 1][w - item.first];
				else
					dp[i][w] = dp[i - 1][w];
				if (dp[i][w] < item.second)
					dp[i][w] = item.second;
			}
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		vc.push_back({ W,V });
	}

	DP();

	cout << dp[N][K];
}