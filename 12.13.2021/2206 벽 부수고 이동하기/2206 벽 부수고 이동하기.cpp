//
//  2206 벽 부수고 이동하기.cpp
//  12.13.2021
//
//  Created by 김택현 on 2021/12/13.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N{}, M{};
string map[1001]{};
queue< pair< pair<int,int>,pair<int,bool> > > q{};
bool visit[1001][1001][2]{};

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool isValidCoord(int row, int col) {
    return 0 <= row && row < N && 0 <= col && col < M;
}
void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

void bfs() {
    q.push({{0,0},{1, false}});
    visit[0][0][0] = true;
    
    while(!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ccnt = q.front().second.first;
        bool flag = q.front().second.second;
        
        q.pop();
        
        if(cr == N - 1 && cc == M - 1) {
            cout << ccnt;
            return;
        }
        
        for(int i{}; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(isValidCoord(nr, nc)) {
                if(map[nr][nc] == '0' && !visit[nr][nc][flag]) {
                    q.push({{nr, nc}, {ccnt + 1, flag}});
                    visit[nr][nc][flag] = true;
                }
                else if(map[nr][nc] == '1' && flag == false) {
                    q.push({{nr,nc}, {ccnt + 1, !flag}});
                    visit[nr][nc][!flag] = true;
                }
            }
            
        }
    }
    cout << -1;
}

int main() {
    __init();
    
    cin >> N >> M;
    
    for(int i{}; i < N; i++)
        cin >> map[i];
    
    bfs();
}
