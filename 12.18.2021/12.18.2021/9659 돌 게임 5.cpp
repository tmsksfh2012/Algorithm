//
//  9659 돌 게임 5.cpp
//  12.18.2021
//
//  Created by 김택현 on 2021/12/18.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string N{};
    
    cin >> N;
    
    int remainder{};
    
    for(auto digit : N) {
        remainder = (remainder * 10 + digit) % 4;
    }
    
    if(remainder % 2 == 0)
        cout << "CY";
    else
        cout << "SK";
}
