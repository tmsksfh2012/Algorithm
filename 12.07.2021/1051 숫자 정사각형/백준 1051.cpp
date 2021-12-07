#include <iostream>
#include <string>
using namespace std;

int R{}, C{}, N{}, ans{};
string map[51]{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool isValidCoord(int x, int y) {
	return x < R && y < C;
}

int findSquare() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int o = 0; o < R; o++) {
				if (isValidCoord(i + o, j + o)) {
					if (map[i][j] == map[i][j + o] 
						&& map[i][j] == map[i + o][j] 
						&& map[i][j] == map[i + o][j + o]) {
						ans = ans > (o + 1) * (o + 1) ? ans : (o + 1) * (o + 1);
					}
				}
			}
		}
	}

	return ans;
}

int main() {
	__init();

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> map[i];

	N = R > C ? R : C;

	cout << findSquare();
}