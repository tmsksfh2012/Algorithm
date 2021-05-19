#include <iostream>
using namespace std;

int main() {
    int N;
    string centence;
    
    cin >> N >> centence;
    
    int res = 0, tmp = 0;
    for(int i = 0; i < N; i++) {
        tmp = centence[i] - '0';
        res += tmp;
    }
    cout << res;
}