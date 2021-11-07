#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int num, ans;

  cin >> num;

  if(num < 100) {
    cout << num;
    return 0;
  }
  ans=99;
  for(int i = 100; i <= num; i++) {
    int fir = i / 100;
    int sec = (i % 100) / 10;
    int thr = (i % 100) % 10;
    if((fir - sec) == (sec - thr)) {
      ans++;
    }
  }
  cout << ans;
}