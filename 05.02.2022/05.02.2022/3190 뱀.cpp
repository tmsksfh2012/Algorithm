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
// 뱀의 현시점 테일 방향 DIR_T
// 0 - 오른쪽 1 - 아래 2 - 왼쪽 3 - 위
int DIR_H{}, DIR_T{};
// 시간 카운트 SUM_SEC
int SUM_SEC{};
// 헤드 위치와 꼬리 위치 HEAD, TAIL
pair<int, int> HEAD{}, pair<int, int> TAIL{};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	DIR_H = 0; DIR_T = 0;

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

	while (!q_L.empty()) {
		pair<int, char> tmp_L = q_L.front();
		q_L.pop();

		int sec = tmp_L.first;
		char dir = tmp_L.second;

		while (SUM_SEC < sec) {
			SUM_SEC++;

			switch (DIR_H) {
			case 0:
				int row = HEAD.first, col = HEAD.second++;
				HEAD = { row, col };
				break;
			case 1:
				int row = HEAD.first++, col = HEAD.second;
				HEAD = { row, col };
				break;
			case 2:
				int row = HEAD.first, col = HEAD.second--;
				HEAD = { row, col };
				break;
			case 3:
				int row = HEAD.first--, col = HEAD.second;
				HEAD = { row, col };
				break;
			}
			// 보드 벽에 부딪혔을 때
			if (HEAD.first > N || HEAD.second > N || HEAD.first < 0 || HEAD.second < 0) {
				cout << SUM_SEC;
				return;
			}
			// 뱀이 자기 몸통에 부짗혔을 때
			else if (board[HEAD.first][HEAD.second] == 2) {
				cout << SUM_SEC;
				return;
			}
			// 뱀이 사과를 못먹었을 때
			else if (board[HEAD.first][HEAD.second] == 0) {
				// 꼬리를 이동시켜준다
				switch (DIR_T) {
				case 0:
					int row = TAIL.first, col = TAIL.second++;
					TAIL = { row, col };
					break;
				case 1:
					int row = TAIL.first++, col = TAIL.second;
					TAIL = { row, col };
					break;
				case 2:
					int row = TAIL.first, col = TAIL.second--;
					TAIL = { row, col };
					break;
				case 3:
					int row = TAIL.first--, col = TAIL.second;
					TAIL = { row, col };
					break;
				}
				// 꼬리가 벽에 닿으면 방향을 
			}
			// 뱀이 사과를 먹었을 때
			else if (board[HEAD.first][HEAD.second] == 1) {

			}
		}
	}
}