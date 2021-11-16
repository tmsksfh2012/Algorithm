#include <iostream>
#include <string>
using namespace std;

string map[51];
int N, M, MIN = 987654321;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

// x와 y는 체스판의 시작 지점
void paintBoard(int x, int y) {
	int cntW{}, cntB{};

	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (map[i][j] == 'B')
					cntW++;
				else
					cntB++;
			}
			else {
				if (map[i][j] == 'B')
					cntB++;
				else
					cntW++;
			}
		}
	MIN = MIN < cntB ? MIN : cntB;
	MIN = MIN < cntW ? MIN : cntW;
}

int main() {
	__init();

	cin >> N >> M;

	for (int i{}; i < N; i++)
		cin >> map[i];

	// 가능한 체스판의 개수는 (N - 8) x (k - 8)까지
	for (int i{}; i <= N - 8; i++)
		for (int j{}; j <= M - 8; j++)
			paintBoard(j, i);

	cout << MIN;
}