#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int main() {
  int N;

  __init();

  cin >> N;
  if(N == 1) cout << 666;
  else if(N == 2) cout << 1666;
  else {
    int carry = (N - 2) / 6;
    int num = (N - 1) % 6;
    if(num) cout << num;
    while(carry--) cout << 6;
    cout << 666;
  }
}