#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Map[1001];
int dp[1001];

bool isValidCoord(int x) {
    return x < N;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> Map[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= Map[i]; ++j) {
            int dx = i + j;

            if(isValidCoord(dx) && (dp[i] > 0 || i == 0)) {
                if (dp[dx] == 0)
                    dp[dx] = dp[i] + 1;
                else
                    dp[dx] = min(dp[dx], dp[i] + 1);
            }
        }
    }

    if(N == 1)
        cout << 0;
    else
        cout << (dp[N-1] > 0 ? dp[N-1] : -1);
}
