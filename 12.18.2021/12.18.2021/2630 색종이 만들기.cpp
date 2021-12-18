//
//  2630 색종이 만들기.cpp
//  12.18.2021
//
//  Created by 김택현 on 2021/12/18.
//

#include <iostream>
#define endl "\n"
using namespace std;

bool map[130][130]{};
int white{}, blue{};

void f(int row, int col, int N) {
    int cnt{};
    
    for(int i = row; i < row + N; i++)
        for(int j = col; j < col + N; j++)
            if(map[i][j])
                cnt++;
    
    if(!cnt) white++;
    else if(cnt == N * N) blue++;
    else {
        f(row,col,N/2);
        f(row, col + N / 2, N/2);
        f(row + N / 2, col, N/2);
        f(row + N / 2, col + N / 2, N/2);
    }
}

int main() {
    int N{};

    cin >> N;
    
    for(int i{}; i < N; i++)
        for(int j{}; j < N; j++)
            cin >> map[i][j];
    
    f(0,0,N);
    
    cout << white << endl << blue;
}
