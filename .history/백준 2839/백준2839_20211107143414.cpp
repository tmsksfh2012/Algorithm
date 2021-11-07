#include <iostream>
#include <algorithm>
using namespace std;

int DP[5001] = {0,};

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int CarrySugar(int num) {
  cout << num << " ";
  if(DP[num]) {
    return DP[num];
  }
  else {
    return DP[num] = min(CarrySugar(num - 3),CarrySugar(num - 5));
  }
}

int main() {
  int N;

  __init();

  for(int i = 0; i < 5000; i++) DP[i] = 9999;

  DP[3] = 1;
  DP[5] = 1;

  cin >> N;
  int ans = CarrySugar(N);
  cout << (ans > 9000 ? -1 : ans) ;
}