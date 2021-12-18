//
//  9657 돌 게임 3.cpp
//  12.17.2021
//
//  Created by 김택현 on 2021/12/17.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num{};
    bool arr[1001] = { 0,1,0,1,1 };
    cin >> num;
    for (int i = 5; i <= 1000; i++)
    {
        if (!arr[i - 1] || !arr[i - 3] || !arr[i - 4])
        {
            arr[i] = true;
        }
        else
            arr[i] = false;
    }
    if (arr[num])
        cout << "SK";
    else
        cout << "CY";}
