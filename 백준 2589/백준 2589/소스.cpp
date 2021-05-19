#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int y, x;
}Dir;

int L, W, ans;
string map[51];
Dir dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };

bool isValidCoord(int y, int x) {
	return 0 <= y && y < L && 0 <= x && x < W;
}

int Bfs(int y, int x) {
	queue<pair<int, int>> q;
	int total = 0;
	int dp[51][51] = { 0, };

	q.push({y, x});
	dp[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = cy + dir[i].y;
			int dx = cx + dir[i].x;
			total = max(total, dp[cy][cx]);

			if (isValidCoord(dy, dx) && map[dy][dx] == 'L' && dp[dy][dx] == 0) {
				q.push({ dy,dx });
				dp[dy][dx] = dp[cy][cx] + 1;
			}
		}
	}

	return total - 1;
}

int main() {
	cin >> L >> W;

	for (int i = 0; i < L; i++)
		cin >> map[i];

	for (int i = 0; i < L; i++)
		for (int j = 0; j < W; j++)
			if (map[i][j] == 'L')
				ans = max(ans, Bfs(i, j));

	cout << ans;
}