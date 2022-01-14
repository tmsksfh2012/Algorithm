//
//  2193 이친수.cpp
//  12.21.2021
//
//  Created by 김택현 on 2021/12/21.
//

#include <iostream>
using namespace std;

int N{};
long long dp[91]{};

void DP() {
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    cin >> N;
    DP();
    cout << dp[N];
}
