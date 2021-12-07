#include <iostream>
using namespace std;

int chk[11]; // 0 -> 미방문 1 -> 방문 2 -> 출발지
int map[11][11]{};
int ans = 987654321, N{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void BackTracking(int cnt, int start, int sum) {
	if (cnt == N) {
		ans = ans > sum ? sum : ans;
	}
	
	else {
		for (int i = 1; i <= N; i++) {
			if (map[start][i] == 0)
				continue;
			if (chk[i] == 1 || start == i)
				continue;
			if (chk[i] == 2) {
				if (cnt == N - 1) {
					BackTracking(cnt + 1, i, sum + map[start][i]);
				}
				else
					continue;
			}
			else {
				chk[i] = 1;
				BackTracking(cnt + 1, i, sum + map[start][i]);
				chk[i] = 0;
			}
		}
	}
}

int main() {
	__init();

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++) {
		chk[i] = 2;
		BackTracking(0, i, 0);
	}
	
	cout << ans;
}