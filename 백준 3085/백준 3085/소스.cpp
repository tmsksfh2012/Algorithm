#include <iostream>
#include <algorithm>
using namespace std;

int N, Max;
char Mat[51][51];

void Swap(int column, int row, bool direction) {
	char tmp = Mat[column][row];

	// ����
	if (direction) {
		Mat[column][row] = Mat[column - 1][row];
		Mat[column - 1][row] = tmp;
	}

	// �¿�
	else {
		Mat[column][row] = Mat[column][row - 1];
		Mat[column][row - 1] = tmp;
	}
}

void Check(int column, int row, bool direction) {
	Swap(column, row, direction);

	int count = 1;
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			// ���� ��
			if (Mat[j][i] == Mat[j - 1][i]) {
				count++;
				Max = max(Max, count);
			}
			else {
				count = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			// �¿� ��
			if (Mat[i][j] == Mat[i][j - 1]) {
				count++;
				Max = max(Max, count);
			}
			else {
				count = 1;
			}
		}
	}
	Swap(column, row, direction);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Mat[i][j];
		}
	}

	// ��� ���� ���鼭 ��, �� swap�ϰ� check
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ���� ��ȯ
			if (i > 0) {
				Check(i, j, true);
			}
			// �¿� ��ȯ
			if (j > 0) {
				Check(i, j, false);
			}
		}
	}

	cout << Max;
}