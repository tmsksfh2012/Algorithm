#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int Max;
int Mat[101][101];
bool chk[101][101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool isValidCoord(int y, int x) {
	return y >= 0 && y <= N && x >= 0 && x <= M;
}

int dfs(int y, int x) {
	int size = 1;
	chk[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isValidCoord(ny, nx) && Mat[ny][nx] && !chk[ny][nx]) size += dfs(ny, nx);
	}
	return size;
}

int main() {
	int r, c;
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		Mat[r][c] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if(!chk[i][j] && Mat[i][j])
				Max = max(Max, dfs(i, j));
		}
	}
	cout << Max;
}