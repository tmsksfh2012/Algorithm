//
//  4256 트리.cpp
//  12.24.2021
//
//  Created by 김택현 on 2021/12/24.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#define endl "\n"

using namespace std;
int T{};
map<int,int> tree{};
int pre[1010]{};
int in[1010]{};

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

void go(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) return;
 
    int root = pre[pre_start];
    int pos = tree[pre[pre_start]];
 
    go(pre_start + 1, pre_start + (pos - in_start), in_start, pos - 1);
    go(pre_start + (pos - in_start) + 1, pre_end, pos + 1, in_end);
    cout << root << " ";
}

int main(int argc, const char * argv[]) {
    __init();
    
    cin >> T;
    
    while(T--) {
        
        int n{};
        
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            int tmp{};
            cin >> tmp;
            pre[i] = tmp;
        }
        
        for(int i = 1; i <= n; i++) {
            int tmp{};
            cin >> tmp;
            in[i] = tmp;
            tree[tmp] = i;
        }
        go(1, n, 1, n);
        cout << endl;
    }
}
