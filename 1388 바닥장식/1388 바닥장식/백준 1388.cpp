//
//  1388 바닥장식.cpp
//
//
//  Created by 김택현 on 2021/12/10.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string map[51]{};
stack < pair<int,int> > s{};
int dx[2] = {0,1};
int dy[2] = {1,0};
int N{}, M{}, cnt{};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

bool isValidCoord(int x, int y) {
    return x < N && y < M;
}

void dfs() {
    int cx = s.top().first;
    int cy = s.top().second;
    
    s.pop();
    
    for(int i{}; i < 2; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        
        if(isValidCoord(nx, ny)) {
            
            s.push({nx,ny});
            
            // 가로
            if(i == 0) {
                if(map[cx][cy] == '|' || map[nx][ny] == '|')
                    cnt++;
            }
            // 세로
            else {
                if(map[cx][cy] == '-' || map[nx][ny] == '-')
                    cnt++;
            }
            dfs();
        }
    }
}

int main() {
    __init();
    
    cin >> N >> M;
    
    for(int i{}; i < N; i++)
        cin >> map[i];
    
    s.push({0,0});
    dfs();
    
    cout << cnt;
}
