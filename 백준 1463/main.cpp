#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000001];

int calculate(int num){
    dp[1] = 0;
    for (int i = 2; i <= num; ++i) {
        dp[i] = dp[i - 1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[num];
}

int main() {
    cin >> N;
    cout << calculate(N);
}
