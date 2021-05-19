#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
string maze[101];
queue<pair<pair<int, int>, int>> q;
bool chk[101][101] = { 0, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool isValidCoord(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs() {
	int x = 0, y = 0, cnt = 0;

	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		cnt = q.front().second;
		q.pop();

		if (x == M - 1 && y == N - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isValidCoord(nx, ny) && maze[ny][nx] == '1' && !chk[ny][nx]) {
				chk[ny][nx] = true;
				q.push(make_pair(make_pair(ny, nx), cnt+1));
			}
		}
	}
}

int main() {

	chk[0][0] = true;
	q.push(make_pair(make_pair(0,0),1));

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> maze[i];
	}
	cout << bfs();
}