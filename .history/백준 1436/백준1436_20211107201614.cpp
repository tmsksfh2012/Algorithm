#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int main() {
  int N, cnt;
  int num = 665;
  string str;

  __init();

  cin >> N;

  while(++num) {
    str = to_string(num);
    if(str.find("666") != -1) cnt++;
    if(cnt == N) {
      cout << num;
      break;
    }
  }
  
}