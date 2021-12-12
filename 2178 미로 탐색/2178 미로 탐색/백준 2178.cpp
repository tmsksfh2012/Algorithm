//
//  백준 2178.cpp
//  2178 미로 탐색
//
//  Created by 김택현 on 2021/12/12.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N{}, M{};
string map[101]{};
bool visit[101][101]{};
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

bool isValidCoord(int row, int col) {
    return 0 <= row && row < N && 0 <= col && col < M;
}

void bfs() {
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visit[0][0] = true;
    
    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int cnt = q.front().second;
        
        visit[cr][cc] = true;
        
        q.pop();
        
        if(cr == N - 1 && cc == M - 1) {
            cout << cnt;
            return;
        }
        
        for(int i{}; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(isValidCoord(nr, nc) && !visit[nr][nc] && map[nr][nc] == '1') {
                q.push({{nr,nc},cnt + 1});
                visit[nr][nc] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    __init();
    
    cin >> N >> M;
    
    for(int i{}; i < N; i++)
        cin >> map[i];
    
    bfs();
}
