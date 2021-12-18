//
//  20004 베스킨라빈스 31.cpp
//  12.18.2021
//
//  Created by 김택현 on 2021/12/18.
//

#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    int A{};
    
    cin >> A;
    
    for(int i = 1; i <= A; i++) {
        if(30 % (i + 1) == 0)
            cout << i << endl;
    }
}
