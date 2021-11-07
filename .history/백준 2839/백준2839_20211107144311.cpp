#include <iostream>
#include <algorithm>
using namespace std;

int DP[5001] = {0,};
bool visit[5001];

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int CarrySugar(int num) {
  visit[num] = true;
  if(DP[num] && visit[num]) {
    return DP[num];
  }
  else {
    return DP[num] = min(CarrySugar(num - 3),CarrySugar(num - 5)) + 1;
  }
}

int main() {
  int N;

  __init();

  DP[1] = 9999;
  DP[2] = 9999;
  DP[3] = 1;
  DP[4] = 9999;
  DP[5] = 1;

  cin >> N;

  int ans = CarrySugar(N);
  
  cout << ans > 9999 ? -1 : ans;
}