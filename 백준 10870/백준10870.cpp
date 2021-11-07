#include <iostream>
using namespace std;

int main() {
  int tk, sum;
  int dp[22];

  dp[0] = 0;
  dp[1] = 1;

  cin >> tk;

  if(tk > 1) {
    for(int i = 2; i <= tk; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
  }
  
  cout << dp[tk];
}