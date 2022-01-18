//
//  10826 피보나치 수 4.cpp
//  01.17.2022
//
//  Created by 김택현 on 2022/01/17.
//

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 18446744073709551615
using namespace std;

int N{};
string dp[10010]{"0", "1", "1", };

string fibonacci(int n) {
    if(!dp[n].empty())
        return dp[n];
    else {
        string sum{};
        string Fnm = fibonacci(n - 1);
        string Fnmm = fibonacci(n - 2);
        
        while(Fnm.size() > Fnmm.size())
            Fnmm.insert(0, "0");
        while(Fnm.size() < Fnmm.size())
            Fnm.insert(0, "0");
        
        int carry{};
        int num{};
        for(int i = Fnm.size() - 1; i >= 0; i--) {
            num = (Fnm[i] -'0' + Fnmm[i] -'0' + carry) % 10;
            carry = (Fnm[i] - '0' + Fnmm[i] -'0' + carry) / 10;
            sum.insert(0, to_string(num));
        }
        if(carry > 0)
            sum.insert(0, to_string(carry));
        
        dp[n] = sum;
        return sum;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    cin >> N;
    
    cout << fibonacci(N);
}
