#include <iostream>
#include <algorithm>
#define DIR 2
using namespace std;

int N, M;
int Maze[1001][1001];
int DP[1001][1001];

typedef struct {
    int y, x;
} Dir;

Dir dir[DIR] = {{0,1},{1,0}};

bool isValidCoord(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> Maze[i][j];

    DP[0][0] = Maze[0][0];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < DIR; ++k) {
                int dy = i + dir[k].y;
                int dx = j + dir[k].x;

                if(isValidCoord(dy, dx))
                    DP[dy][dx] = max(DP[dy][dx], DP[i][j] + Maze[dy][dx]);
            }
        }
    }

    cout << DP[N-1][M-1];
}