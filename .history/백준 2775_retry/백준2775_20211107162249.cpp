#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int getNum(int k, int n) {
  if(k == 0) return n;
  if(n == 1) return 1;

  return getNum(k - 1, n) + getNum(k, n - 1);
}

int main() {
  int tc, k, n;

  __init();

  cin >> tc;

  while(tc--) {
    cin >> k >> n;
    cout << getNum(k, n) << "\n";
  }
}