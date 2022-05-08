#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// 덱을 써서 꼬리물기 식으로 코딩한다.

// 보드 크기 N
// 벽의 경계 -> N + 1
// 뱀의 시작 위치 -> (0, 0)
// 뱀의 시작 머리 방향 -> 오른쪽
int N{};
// 사과의 개수 K
int K{};
// 보드판
// 1 - 사과 있음 / 0 - 사과 없음 / 2 - 현재 뱀의 몸통이 위치함
int board[101][101]{};
// 뱀의 방향 변환 횟수 L
int L{};
// 뱀의 방향 변환 정보 q_L
queue<pair<int, char>> q_L{};
// 뱀의 현시점 헤드 방향 DIR_H
// 0 - 오른쪽 1 - 아래 2 - 왼쪽 3 - 위
int DIR_H{};
// 시간 카운트 SUM_SEC
int SUM_SEC{};
// 뱀의 정보
deque<pair<int, int>> snake{};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	DIR_H = 0; snake.push_back({ 1,1 });

	cin >> N >> K;

	// 사과 위치 입력
	for (int i{}; i < K; i++) {
		int row{}, col{};
		cin >> row >> col;

		board[row][col] = 1;
	}

	cin >> L;

	for (int i{}; i < L; i++) {
		int sec{}; char dir{};
		cin >> sec >> dir;
		q_L.push({ sec, dir });
	}
	// 빙향 지시가 있는 경우
	while (!q_L.empty()) {
		pair<int, char> tmp_L = q_L.front();
		q_L.pop();

		int sec = tmp_L.first;
		char dir = tmp_L.second;

		// 다음 방향 지시가 있기 전까지 기존 방향으로 진행한다.
		while (SUM_SEC < sec) {
			SUM_SEC++;
			int row = snake.front().first, col = snake.front().second;

			switch (DIR_H) {
			// 오른쪽
			case 0:
				col++;
				break;
			// 아래
			case 1:
				row++;
				break;
			// 왼쪽
			case 2:
				col--;
				break;
			// 위
			case 3:
				row--;
				break;
			}

			// 에러 처리 부분
			// 벽에 부딪치는 경우
			if (row > N || col > N || row < 1 || col < 1) {
				cout << SUM_SEC;
				return 0;
			}
			// 자기 몸에 부딪치는 경우
			else {
				for (auto dir : snake) {
					if (dir.first == row && dir.second == col) {
						cout << SUM_SEC;
						return 0;
					}
				}
			}

			// 뱀이 사과를 못먹었을 때
			if (board[row][col] == 0) {
				// 꼬리를 이동시켜준다
				snake.pop_back();
			}
			// 뱀이 사과를 먹었을 때
			else if (board[row][col] == 1)
				// 꼬리는 그대로, 사과는 제거
				board[row][col] = 0;

			snake.push_front({ row,col });
		}
		// 진행을 마치고 방향 지시를 받는다.
		switch (dir) {
		// 오른쪽으로 방향 전환
		case('D'):
			DIR_H++;
			break;
		// 왼쪽으로 방향 전환
		case('L'):
			DIR_H--;
			break;
		}
		if (DIR_H == 4)
			DIR_H = 0;
		else if (DIR_H == -1)
			DIR_H = 3;
	}
	// 방향 지시가 없는 경우
	// 기존 방향으로 계속해서 진행한다.
	while (1) {
		SUM_SEC++;
		int row = snake.front().first, col = snake.front().second;
		switch (DIR_H) {
			// 오른쪽
		case 0:
			col++;
			break;
			// 아래
		case 1:
			row++;
			break;
			// 왼쪽
		case 2:
			col--;
			break;
			// 위
		case 3:
			row--;
			break;
		}

		// 에러 처리 부분
		// 벽에 부딪치는 경우
		if (row > N || col > N || row < 1 || col < 1) {
			cout << SUM_SEC;
			return 0;
		}
		// 자기 몸에 부딪치는 경우
		else {
			for (auto dir : snake) {
				if (dir.first == row && dir.second == col) {
					cout << SUM_SEC;
					return 0;
				}
			}
		}

		// 뱀이 사과를 못먹었을 때
		if (board[row][col] == 0) {
			// 꼬리를 이동시켜준다
			snake.pop_back();
		}
		// 뱀이 사과를 먹었을 때
		else if (board[row][col] == 1)
			// 꼬리는 그대로, 사과는 제거
			board[row][col] = 0;

		snake.push_front({ row,col });
	}
}