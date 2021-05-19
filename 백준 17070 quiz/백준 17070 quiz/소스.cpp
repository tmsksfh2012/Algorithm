#include <iostream>
using namespace std;

int N;
int mat[16][16];

//����, ����, �밢��
int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 0, 1 };
int ans;

void F(int y, int x, int pipe) {
	if (y == N - 1 && x == N - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		//���� ���¿��� ���η� ������ ���, ���� ���¿��� ���η� ������ ��� ����
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0)) {
			continue;
		}

		int ny = y + dy[i];
		int nx = x + dx[i];

		//������ ����ų� ���� ��� ����
		if (nx >= N || ny >= N || mat[ny][nx] == 1) {
			continue;
		}
		//�밢������ �����µ� ���� ��� ����
		if (i == 2 && (mat[y][x + 1] == 1 || mat[y + 1][x] == 1)) {
			continue;
		}
		F(ny, nx, i);
	}
}

int main() {
	cin >> N;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	F(0, 1, 0);
	cout << ans;
}