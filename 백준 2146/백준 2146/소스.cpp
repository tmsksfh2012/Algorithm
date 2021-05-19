#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N, ans = 987654321;
int map[100][100];
bool visited[100][100];

typedef struct {
	int y, x;
}Dir;

Dir dir[4] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

bool isValidCoord(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

void dfs(int y, int x, int cnt) {
	visited[y][x] = true;
	map[y][x] = cnt;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i].y;
		int nx = x + dir[i].x;
		
		if (isValidCoord(ny, nx) && !visited[ny][nx] && map[ny][nx] == 1) {
			dfs(ny, nx, cnt);
		}
	}
}

int bfs(int cnt) {
	deque <pair<int, int>> dq;
	int res = 0;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if(map[i][j] == cnt) {
				dq.push_back({ i,j });
				visited[i][j] = true;
			}
		}

	while (!dq.empty()) {

		int curSize = dq.size();
		for (int i = 0; i < curSize; i++) {
			int cy = dq.front().first;
			int cx = dq.front().second;

			dq.pop_front();

			for (int i = 0; i < 4; i++) {
				int ny = cy + dir[i].y;
				int nx = cx + dir[i].x;

				if (isValidCoord(ny, nx)) {
					if (map[ny][nx] && map[ny][nx] != cnt) return res;

					else if (!map[ny][nx] && !visited[ny][nx]) {
						dq.push_back({ ny,nx });
						visited[ny][nx] = true;
					}
				}
			}
		}
		res++;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}

	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) dfs(i, j, ++count);
		}

	for (int i = 1; i <= count; i++) {
		memset(visited, false, sizeof(visited));

		int tmp = bfs(i);
		ans = ans > tmp ? tmp : ans;
	}
	cout << ans;
}