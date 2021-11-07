#include <iostream>
#include <algorithm>
using namespace std;

int DP[5001];

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int CarrySugar(int num) {
  if(DP[num]) {
    return DP[num];
  }
  else {
    return DP[num] = min(CarrySugar(num - 3),CarrySugar(num - 5)) + 1;
  }
}

int main() {
  int N;

  __init();

  DP[1] = INT_MAX;
  DP[2] = INT_MAX;
  DP[3] = 1;
  DP[4] = INT_MAX;
  DP[5] = 1;

  cin >> N;

  int ans = CarrySugar(N);
  
  cout << (ans > 9999 ? -1 : ans);
}