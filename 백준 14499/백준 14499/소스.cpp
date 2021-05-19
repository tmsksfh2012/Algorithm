#include <iostream>
#define DICE 6
#define MAP_MAX 21
using namespace std;

int N, M, K;
// �ֻ����� ��ǥ
int diceCol, diceRow;

// �ֻ����� ���ڸ� ����
int diceNum[DICE] = { 0 };
// �ֻ��� �ε���. ��, ��, ������, ��, ����, �Ʒ�
int diceIdx[DICE] = { 1, 5, 3, 2, 4, 6 };
int map[MAP_MAX][MAP_MAX];

// �ֻ����� �ε����� �����Ѵ�.
void ChangeDiceIdx(int moveWay) {
	int sub = diceIdx[0];
	switch (moveWay) {
		// ��
	case 1:
		diceIdx[0] = diceIdx[4];
		diceIdx[4] = diceIdx[5];
		diceIdx[5] = diceIdx[2];
		diceIdx[2] = sub;
		break;
		// ��
	case 2:
		diceIdx[0] = diceIdx[2];
		diceIdx[2] = diceIdx[5];
		diceIdx[5] = diceIdx[4];
		diceIdx[4] = sub;
		break;
		// ��
	case 3:
		diceIdx[0] = diceIdx[1];
		diceIdx[1] = diceIdx[5];
		diceIdx[5] = diceIdx[3];
		diceIdx[3] = sub;
		break;
		// ��
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

// �ֻ����� �������� �����Ѵ�.
int changeDicePos(int moveWay) {
	int chk = 0;
	switch (moveWay) {

		// ��
	case 1:
		if (diceCol + 1 < M) {
			diceCol += 1;
			chk = 1;
		}
		break;
		// ��
	case 2:
		if (diceCol - 1 >= 0) {
			diceCol -= 1;
			chk = 1;
		}
		break;
		// ��
	case 3:
		if (diceRow - 1 >= 0) {
			diceRow -= 1;
			chk = 1;
		}
		break;
		// ��
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

// �ֻ��� ������
int Rolling(int moveWay) {
	if (changeDicePos(moveWay) == 0)
		return -1;

	ChangeDiceIdx(moveWay);

	// �ֻ����� ������ ��, �̵��� ĭ�� �� �ִ� ���� 0
	if (map[diceRow][diceCol] == 0) {
		map[diceRow][diceCol] = diceNum[diceIdx[DICE - 1] - 1];
	}
	// 0�� �ƴ� ���
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