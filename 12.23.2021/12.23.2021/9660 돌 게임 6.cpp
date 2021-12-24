//
//  9660 돌 게임 6.cpp
//  12.23.2021
//
//  Created by 김택현 on 2021/12/23.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    {
        long long n;
        
        cin >> n;
        
        if (n % 7 == 0 || n % 7 == 2) {
            cout << "CY" << endl;
        }
        else {
            cout << "SK" << endl;
        }
     
        return 0;
    }
}
