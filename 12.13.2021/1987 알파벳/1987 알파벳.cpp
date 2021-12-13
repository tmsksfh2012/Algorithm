//
//  1987 알파벳.cpp
//  12.13.2021
//
//  Created by 김택현 on 2021/12/13.
//

#include <iostream>
#include <string>
using namespace std;

int R{}, C{}, ans{};
string str[21]{};
bool alpha[26]{};

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

bool isValidCoord(int row, int col) {
    return 0 <= row &&  row < R && 0 <= col && col < C;
}

void dfs(int row, int col, int cnt) {
    int cha = str[row][col] - 'A';
    
    // 방문 체크를 어디서 할지 주의하자
    ans = ans > cnt ? ans : cnt;
    alpha[cha] = true;
    
    for(int i{}; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        cha = str[nr][nc] - 'A';
        
        if(isValidCoord(nr, nc) && !alpha[cha]) {
            dfs(nr, nc, cnt + 1);
        }
    }
    // 방문 체크 해제를 어디서 할지 주의하자
    alpha[str[row][col] - 'A'] = false;
}

int main() {
    __init();
    
    cin >> R >> C;
    
    for(int i{}; i < R; i++)
        cin >> str[i];
    
    alpha[str[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    
    cout << ans;
}
