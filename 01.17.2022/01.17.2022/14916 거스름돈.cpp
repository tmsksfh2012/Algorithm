//
//  14916 거스름돈.cpp
//  01.17.2022
//
//  Created by 김택현 on 2022/01/17.
//

#include <iostream>
using namespace std;

int dp[100001]{}, coin[2] = {2, 5};
int n{}, ans{};

int DP(int num) {
        if(num < 0) return 2e9;
        if(num == 0) return 0;
        if(dp[num] > 0) return dp[num];
    
        int res = 2e9;
        
    for(int i{}; i < 2; i++) {
        int cnt = DP(num - coin[i]) + 1;
        res = res < cnt ? res : cnt;
        dp[num] = res;
    }
    
    return res;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    cin >> n;
    
    if(n % 5 == 0) cout << n / 5;
    
    else {
        int res = DP(n);
        if(res == 2e9) cout << -1;
        else cout << res;
    }
    
    
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//
//    int n, sum = 0;
//    cin >> n;
//    if (n == 1 || n == 3) {
//        cout << "-1";
//        return 0;
//    }
//    if (n % 5 % 2 == 0) {
//        sum = n / 5 + n % 5 / 2;
//    }
//    else {
//        sum = n / 5 + (n % 5 + 5) / 2 - 1;
//    }
//
//    cout << sum;
//    return 0;
//}
