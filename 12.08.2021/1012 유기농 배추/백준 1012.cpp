#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define endl "\n"
using namespace std;

int M{}, N{}, K{}, cnt{};
int map[51][51]{};
bool chk[51][51]{};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool isValidCoord(int row, int col) {
	return 0 <= row && row < M && 0 <= col && col < N;
}

void BFS(int row, int col) {
	queue<pair<int, int>> q;

	if (!chk[row][col]) {
		q.push({ row,col });
		chk[row][col] = true;
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		chk[cx][cy] = true;

		q.pop();

		for (int i{}; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (isValidCoord(nx, ny) && !chk[nx][ny] && map[nx][ny] == 1) {
				q.push({ nx,ny });
				chk[nx][ny] = true;
			}
		}
	}
	cnt++;
}

int main() {
	__init();

	int Tc{};

	cin >> Tc;
	while (Tc--) {
		cin >> N >> M >> K;

		vector<pair<int, int>> vc{};

		for (int i{}; i < K; i++) {
			int row{}, col{};

			cin >> col >> row;

			map[row][col] = 1;

			vc.push_back({ row,col });
		}

		for (auto pair : vc) {
			if(!chk[pair.first][pair.second])
				BFS(pair.first, pair.second);
		}
		cout << cnt << endl;
		cnt = 0;

		memset(chk, 0, sizeof(chk));
		memset(map, 0, sizeof(map));
	}
}