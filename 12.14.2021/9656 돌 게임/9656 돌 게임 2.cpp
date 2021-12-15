//
//  9656 돌 게임 2.cpp
//  12.14.2021
//
//  Created by 김택현 on 2021/12/14.
//

#include <iostream>
using namespace std;

int main() {
    int N{}, ans{};
    
    cin >> N;
    ans = N % 4;
    
    if(ans % 2 == 1)
        cout << "CY";
    else
        cout << "SK";
}
