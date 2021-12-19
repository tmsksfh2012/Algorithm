//
//  1359 복권.cpp
//  12.19.2021
//
//  Created by 김택현 on 2021/12/19.
//

#include <iostream>
using namespace std;

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

double combination(double x, double y) {
    if(y == 1)
        return x / y;
    if(y == 0)
        return 1;
    
    return (x / y) * combination(x - 1, y - 1);
}

int main() {
    __init();
    
    int N{}, M{}, K{};
    
    cin >> N >> M >> K;
    
    double prob = combination(N, M);
    double ans{};
    
    double sum{};
    for(int i = K; i <= M; i++) {
        sum += combination(M, i) * combination(N - M, M - i);
    }
    
    ans += sum / prob;
    
    cout << fixed;
    cout.precision(16);
    cout << ans;
}
