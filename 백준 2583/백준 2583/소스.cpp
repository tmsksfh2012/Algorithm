#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int Max;
bool Map[101][101];
bool chk[101][101];
vector<int> empties;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool isValidCoord(int y, int x) {
	return y > 100 - M && y <= 100 && x >= 0 && x < N;
}

int dfs(int y, int x) {
	int size = 1;
	chk[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isValidCoord(ny, nx) && !Map[ny][nx] && !chk[ny][nx]) size += dfs(ny, nx);
	}
	return size;
}

int main() {
	cin >> M >> N >> K;

	int y1, x1, y2, x2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		y1 = 100 - y1;
		y2 = 100 - y2;
		for (int i = y1; i > y2; i--) {
			for (int j = x1; j < x2; j++) {
				Map[i][j] = true;
			}
		}
	}
	for (int i = 100; i > 100 - M; i--) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j] && !Map[i][j]) {
				empties.push_back(dfs(i, j));
				Max++;
			}
		}
	}
	cout << Max << endl;
	sort(empties.begin(), empties.end());
	for (int i = 0; i < empties.size(); i++) cout << empties[i] << " ";
}