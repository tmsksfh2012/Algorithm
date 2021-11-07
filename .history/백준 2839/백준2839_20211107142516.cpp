#include <iostream>
#include <algorithm>
using namespace std;

int DP[5001];

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
    return DP[num] = min(CarrySugar(DP[num - 3]),CarrySugar(DP[num - 5]));
  }
}

int main() {
  int N;

  __init();

  DP[1] = -1;
  DP[2] = -1;
  DP[3] = 1;
  DP[4] = -1;
  DP[5] = 1;

  cin >> N;
  cout << CarrySugar(N);
}