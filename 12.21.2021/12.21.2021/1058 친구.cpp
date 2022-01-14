//
//  1058 친구.cpp
//  12.21.2021
//
//  Created by 김택현 on 2021/12/21.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N{}, ans{};
string str[51]{};
vector<int> vc[51]{};

void dfs(int x) {
    int cnt{};
    bool chk[51]{};
    
    for(int i{}; i < vc[x].size(); i++) {
        if(!chk[vc[x][i]]) {
            cnt++;
            chk[vc[x][i]] = true;
        }
        for(auto idx : vc[vc[x][i]]) {
            if(idx == x)
                continue;
            if(!chk[idx]) {
                cnt++;
                chk[idx] = true;
            }
        }
    
        ans = ans > cnt ? ans : cnt;
    }
}

int main(int argc, const char * argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    
    for(int i{}; i < N; i++)
        cin >> str[i];
    
    for(int i{}; i < N; i++)
        for(int j{}; j < N; j++) {
            if(str[i][j] == 'Y')
            vc[i].push_back(j);
        }
    
    for(int i{}; i < N; i++)
        dfs(i);
    
    cout << ans;
}
