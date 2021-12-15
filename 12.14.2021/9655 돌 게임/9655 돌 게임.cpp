//
//  9655 돌게임.cpp
//  12.14.2021
//
//  Created by 김택현 on 2021/12/14.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N{}, sol{};
    cin >> N;
    
    sol = N % 4;
    
    if(sol % 2 == 1)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
