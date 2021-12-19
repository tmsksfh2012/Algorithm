//
//  14613 너의 티어는? using dp.cpp
//  12.19.2021
//
//  Created by 김택현 on 2021/12/19.
//

#include <iostream>
#define endl "\n"
using namespace std;

double dp[21][3001]{};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main(int argc, const char * argv[]) {
    __init();
    
    dp[0][2000] = 1;
    
    double W{}, L{}, D{}, bronze{}, silver{}, gold{}, platinum{}, diamond{};
    
    cin >> W >> L >> D;
    
    for(int i = 1; i <= 20; i++)
        for(int j = 1000; j <= 3000; j++) {
            if(dp[i - 1][j] == 0)
                continue;
            
            dp[i][j - 50] += dp[i - 1][j] * L;
            dp[i][j + 50] += dp[i - 1][j] * W;
            dp[i][j] += dp[i - 1][j] * D;
        }
    
    for(int i = 1000; i <= 3000; i++) {
        if(1000 <= i && i <= 1499) bronze += dp[20][i];
        else if(1500 <= i && i <= 1999) silver += dp[20][i];
        else if(2000 <= i && i <= 2499) gold += dp[20][i];
        else if(2500 <= i && i <= 2999) platinum += dp[20][i];
        else diamond += dp[20][i];
    }
    
    cout << fixed;
    cout.precision(8);
    
    cout << bronze << endl;
    cout << silver << endl;
    cout << gold << endl;
    cout << platinum << endl;
    cout << diamond;
}
