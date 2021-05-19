#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#define MAX 501
using namespace std;

int N, ans;
int map[MAX][MAX];
int dp[MAX][MAX];

typedef struct {
	int y, x;
}Dir;

Dir dir[4] = { {0,1},{1,0},{-1,0}, {0,-1} };

bool isValidCoord(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

int Dfs(int y, int x) {
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int dy = y + dir[i].y;
		int dx = x + dir[i].x;
		if (isValidCoord(dy, dx) && map[y][x] < map[dy][dx]) {
			dp[y][x] = max(dp[y][x], Dfs(dy, dx) + 1);
		}
	}
	return dp[y][x];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			ans = max(ans, Dfs(i, j));
		}

	cout << ans;
}