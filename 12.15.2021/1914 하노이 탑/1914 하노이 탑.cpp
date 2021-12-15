//
//  1914 하노이 탑.cpp
//  12.15.2021
//
//  Created by 김택현 on 2021/12/15.
//

#include <iostream>
#include <math.h>
#include <string>
#define endl "\n"
using namespace std;

int N{};

void f(int from, int to, int bridge, int cnt) {
    if(cnt == 1) {
        cout << from << " " << to << endl;
        return;
    }
    
    f(from, bridge, to, cnt - 1);
    cout << from << " " << to << endl;
    f(bridge, to, from, cnt - 1);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    string ans = to_string(pow(2, N));
    int idx = ans.find('.');
    ans = ans.substr(0, idx);
    ans[ans.size() - 1] -= 1;
    cout << ans << endl;
    
    if(N <= 20)
        f(1,3,2,N);
}
