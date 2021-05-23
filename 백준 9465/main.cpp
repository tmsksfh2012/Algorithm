#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n;
int map[2][100001];
int dp[2][100001];
//
//bool isValidDiagonal(int chkNum) {
//    return chkNum > 0;
//}
//
//bool isValidSideLine(int chkNum) {
//    return chkNum > 1;
//}

int calculate(int num){
//    for (int i = 0; i < 2; ++i)
//        for (int j = 0; j < num; ++j)
//            dp[i][j] = map[i][j];

//    for (int i = 0; i < num; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            if(isValidSideLine(i)) {
//                dp[j][i] = max(dp[j][i], dp[j ? 0 : 1][i - 2] + map[j][i]);
//            }
//            if(isValidDiagonal(i)) {
//                dp[j][i] = max(dp[j][i], dp[j ? 0 : 1][i - 1] + map[j][i]);
//            }
//        }
//    }

    for (int j = 2; j < num + 2; ++j) {
        for (int i = 0; i < 2; ++i) {
            if(i == 1) dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
            else dp[i][j] += max(dp[i +1][j - 1], dp[i + 1][j - 2]);
        }
    }

    return max(dp[0][num + 1], dp[1][num + 1]);
}

int main() {
    cin >> T;

    while(T--) {
        cin >> n;
//        for (int i = 0; i < 2; ++i)
//            for (int j = 0; j < n; ++j)
//                cin >> map[i][j];
        for (int i = 0; i < 2; ++i)
            for (int j = 2; j < n + 2; ++j)
                cin >> dp[i][j];

        cout << calculate(n) << endl;
        memset(dp, 0, sizeof(dp));
    }
}
