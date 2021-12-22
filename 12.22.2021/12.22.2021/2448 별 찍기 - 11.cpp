//
//  2448 별 찍기 - 11.cpp
//  12.22.2021
//
//  Created by 김택현 on 2021/12/22.
//

#include <iostream>
#define endl "\n"
using namespace std;

int N{};
bool map[4000][8000]{};
int ccnt{};

void __init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
}

void f(int num, int row, int col) {
    if(num == 3) {
        ccnt++;
        cout << "row: " << row << " / ccnt: " << ccnt << endl;
        map[row][col] = !map[row][col];
        map[row + 1][col - 1] = !map[row + 1][col - 1];
        map[row + 1][col + 1] = !map[row + 1][col + 1];
        for(int i = col - 2; i <= col + 2; i++)
            map[row + 2][i] = !map[row + 2][i];
    }
    else {
        f(num / 2, row, col);
        f(num / 2, row + num / 2, col - num / 2);
        f(num / 2, row + num / 2, col + num / 2);
    }
}

int main(int argc, const char * argv[]) {
    __init();
    cin >> N;
    
    int row = 0;
    
    f(N, row, N - 1);
    
    for(int i{}; i < N; i++) {
        for(int j{}; j < 2 * N; j++) {
            if(map[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
