#include <iostream>
#define DICE 6
#define MAP_MAX 21
using namespace std;

int N, M, K;
// 주사위의 좌표
int diceCol, diceRow;

// 주사위에 숫자를 저장
int diceNum[DICE] = { 0 };
// 주사위 인덱스. 위, 뒤, 오른쪽, 앞, 왼쪽, 아래
int diceIdx[DICE] = { 1, 5, 3, 2, 4, 6 };
int map[MAP_MAX][MAP_MAX];

// 주사위의 인덱스를 결정한다.
void ChangeDiceIdx(int moveWay) {
	int sub = diceIdx[0];
	switch (moveWay) {
		// 동
	case 1:
		diceIdx[0] = diceIdx[4];
		diceIdx[4] = diceIdx[5];
		diceIdx[5] = diceIdx[2];
		diceIdx[2] = sub;
		break;
		// 서
	case 2:
		diceIdx[0] = diceIdx[2];
		diceIdx[2] = diceIdx[5];
		diceIdx[5] = diceIdx[4];
		diceIdx[4] = sub;
		break;
		// 북
	case 3:
		diceIdx[0] = diceIdx[1];
		diceIdx[1] = diceIdx[5];
		diceIdx[5] = diceIdx[3];
		diceIdx[3] = sub;
		break;
		// 남
	case 4:
		diceIdx[0] = diceIdx[3];
		diceIdx[3] = diceIdx[5];
		diceIdx[5] = diceIdx[1];
		diceIdx[1] = sub;
		break;
	default:
		break;
	}
}

// 주사위의 포지션을 변경한다.
int changeDicePos(int moveWay) {
	int chk = 0;
	switch (moveWay) {

		// 동
	case 1:
		if (diceCol + 1 < M) {
			diceCol += 1;
			chk = 1;
		}
		break;
		// 서
	case 2:
		if (diceCol - 1 >= 0) {
			diceCol -= 1;
			chk = 1;
		}
		break;
		// 북
	case 3:
		if (diceRow - 1 >= 0) {
			diceRow -= 1;
			chk = 1;
		}
		break;
		// 남
	case 4:
		if (diceRow + 1 < N) {
			diceRow += 1;
			chk = 1;
		}
		break;

	default:
		break;
	}
	return chk;
}

// 주사위 돌리기
int Rolling(int moveWay) {
	if (changeDicePos(moveWay) == 0)
		return -1;

	ChangeDiceIdx(moveWay);

	// 주사위를 굴렸을 때, 이동한 칸에 써 있는 수가 0
	if (map[diceRow][diceCol] == 0) {
		map[diceRow][diceCol] = diceNum[diceIdx[DICE - 1] - 1];
	}
	// 0이 아닌 경우
	else {
		diceNum[diceIdx[DICE - 1] - 1] = map[diceRow][diceCol];
		map[diceRow][diceCol] = 0;
	}
	return 1;
}

int main() {
	cin >> N >> M >> diceRow >> diceCol >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int moveWay;
	for (int i = 0; i < K; i++) {
		scanf("%d", &moveWay);
		if (Rolling(moveWay) == 1)
			printf("%d\n", diceNum[diceIdx[0] - 1]);
	}
	return 0;
}