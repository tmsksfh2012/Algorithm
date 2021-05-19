#include <iostream>
using namespace std;

bool Mat[1001][1001] = { 0, }, chk[1001];
int ans, N, M;;

void dfs(int now) {
	chk[now] = true;
	for (int i = 1; i <= N; i++) {
		if (Mat[now][i] && !chk[i]) {
			dfs(i);
		}
	}
}

int main() {
	cin >> N >> M;

	int u, v;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		Mat[u][v] = Mat[v][u] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (!chk[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}