//
//  2491 수열.cpp
//  01.18.2022
//
//  Created by 김택현 on 2022/01/18.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    // 0 -> UP / 1 -> DOWN
    int N{}, arr[100001]{}, dp[100001][2]{}, ans = 1;
    
    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[1][0] = 1;
    dp[1][1] = 1;
    
    for(int i = 2; i <= N; i++) {
        // Up case
        if(arr[i - 1] < arr[i]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = 1;
        }
        // Down case
        else if(arr[i - 1] > arr[i]) {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = 1;
        }
        // Same case
        else {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        ans = ans > dp[i][0] ? ans : dp[i][0];
        ans = ans > dp[i][1] ? ans : dp[i][1];
    }
    
    cout << ans;
}
