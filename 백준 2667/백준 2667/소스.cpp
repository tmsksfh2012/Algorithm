#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Max;
string Map[25];
bool chk[25][25];
vector<int> buildings;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool isValidCoord(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < N;
}

int dfs(int y, int x) {
	int size = 1;
	chk[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isValidCoord(ny, nx) && Map[ny][nx] == '1' && !chk[ny][nx]) size += dfs(ny, nx);
	}
	return size;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Map[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j] && Map[i][j] == '1'){
				buildings.push_back(dfs(i, j));
				Max++;
			}
		}
	}
	cout << Max << endl;
	sort(buildings.begin(), buildings.end());
	for (int i = 0; i < buildings.size(); i++) cout << buildings[i] << endl;
}