#include <iostream>
#include <queue>
using namespace std;
// 연구소 크기 NxM
int N{}, M{};
// 연구소 최대 크기 8x8
// 0 -> 빈칸 / 1 -> 벽 / 2 -> 바이러스
int map[10][10]{};
// 방문 확인용 Matrix
bool chk[10][10]{};
// bfs를 위한 큐
// pair< pair<위치 정보>,  벽의 개수>
queue<pair<pair<int, int>,int>> q{};
// 이동을 위한 방향 행렬
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
// 최종 가능 범위
int SUM{};

// 지도 내에서 유효한 경로 파악 함수
bool isValidCoord(int r, int c) {
	return r > 0 && c > 0 && r < N && c < M;
}

void bfs() {
	// 현재 범위 내 최대 가용 범위
	int sum{};
	q.push({ {0, 0}, 0 });

	while (!q.empty()) {
		pair<int, int> c_dir = q.front().first;
		int cnt = q.front().second;
		int cr = c_dir.first; int cc = c_dir.second;

		q.pop();

		if (!isValidCoord(cr, cc) || chk[cr][cc]) {
			sum = sum > cnt : sum ? cnt;
		}

		if (cnt == 3) {
			for (int i{}; i < 4; i++) {
				int nr = cr + dr[i];
				int nc = cc + dc[i];
			}
		}
	}
	SUM += sum;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i{}; i < N; i++) {
		for (int j{}; j < N; j++) {
			cin >> map[i][j];
		}
	}

	bfs();
}