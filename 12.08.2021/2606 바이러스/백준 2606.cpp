#include <iostream>
using namespace std;

int Mat[101][101]{};
int N, K, ans;
bool visit[101]{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void dfs(int num) {
	ans++;
	visit[num] = true;

	for (int i = 1; i <= N; i++)
		if (Mat[num][i] && !visit[i])
			dfs(i);
}

int main() {
	__init();

	cin >> N >> K;

	int start, to;
	for (int i{}; i < K; i++) {
		cin >> start >> to;
		Mat[start][to] = 1;
		Mat[to][start] = 1;
	}

	dfs(1);
	cout << ans - 1;
}