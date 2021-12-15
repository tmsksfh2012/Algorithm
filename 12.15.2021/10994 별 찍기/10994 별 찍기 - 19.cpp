//
//  10994 별 찍기 - 19.cpp
//  12.15.2021
//
//  Created by 김택현 on 2021/12/15.
//

#include <iostream>
#include <math.h>
#define endl "\n"
using namespace std;

bool map[400][400]{};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

void f(int num, int cnt) {
    if(num == 1) {
        map[cnt][cnt] = true;
    }
    else{
        int len = 4 * (num - 1) + 1;
    
        for(int i = cnt; i < cnt + len; i++) {
            map[i][cnt] = true;
            map[i][cnt + len - 1] = true;
            map[cnt][i] = true;
            map[cnt + len - 1][i] = true;
        }
        f(num - 1, cnt + 2);
    }
}
int main() {
    __init();
    
    int N{};
    
    cin >> N;
    f(N,0);
    
    int len = 4 * (N - 1) + 1;
    for (int i{}; i < len; i++) {
        for(int j{}; j < len; j++) {
            if(map[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
