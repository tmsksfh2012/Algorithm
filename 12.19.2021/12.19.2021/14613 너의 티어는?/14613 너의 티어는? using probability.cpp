//
//  14613 너의 티어는? using probability.cpp
//  12.19.2021
//
//  Created by 김택현 on 2021/12/19.
//

#include <iostream>
#include <math.h>
#define endl "\n"
#define N 20
#define score 2000
using namespace std;

double ans[5]{};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

double factorial(int num) {
    if(num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main() {
    __init();
    
    double W{}, L{}, D{};
    
    cin >> W >> L >> D;
    
    for(int w_cnt = 0; w_cnt <= N; w_cnt++) {
        for(int l_cnt = N - w_cnt; l_cnt >= 0; l_cnt--) {
            int d_cnt = N - w_cnt - l_cnt;
            
            int prob_score = score + (w_cnt * 50) - (l_cnt * 50);
            
            if(prob_score < 1000 || prob_score > 3500)
                continue;
            
            double prob = pow(W, w_cnt) * pow(L, l_cnt) * pow(D, d_cnt) * factorial(20)
            / (factorial(w_cnt) * factorial(l_cnt) * factorial(d_cnt));
            
            ans[(prob_score - 1000) / 500] += prob;
        }
    }
    
    cout << fixed;
    cout.precision(8);
    for(auto prob : ans)
        cout << prob << endl;
}
