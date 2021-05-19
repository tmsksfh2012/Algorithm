#include <iostream>

using namespace std;

int Mat[101][101];
int N, Line, ans;
bool visit[101] = { 0, };

void dfs(int num) {
	ans++;
	visit[num] = true;

	for (int i = 1; i <= N; i++) {
		if (Mat[num][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int main() {

	cin >> N >> Line;

	int fir, sec;
	for (int i = 1; i <= Line; i++) {
		cin >> fir >> sec;
		Mat[fir][sec] = 1;
		Mat[sec][fir] = 1;
	}

	dfs(1);
	cout << ans-1;
}