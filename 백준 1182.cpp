//
//  main.cpp
//  1182 부분수열의 합
//
//  Created by 김택현 on 2021/12/12.
//

#include <iostream>
#include <vector>
using namespace std;
int N{}, S{}, cnt{};
vector<int> arr;

void __init() {
    cin.tie(0);
    ios::sync_with_stdio(0);
}

void backTracking(int idx, int sum) {
    sum += arr[idx];
    
    if(idx >= N)
        return;
    if(sum == S)
        cnt++;
    
    backTracking(idx + 1, sum);
    backTracking(idx + 1, sum - arr[idx]);
}

int main(int argc, const char * argv[]) {
    __init();
    
    cin >> N >> S;
    
    for(int i{}; i < N; i++) {
        int tmp{};
        cin >> tmp; arr.push_back(tmp);
    }
    
   
    backTracking(0, 0);
    
    cout << cnt;
}
