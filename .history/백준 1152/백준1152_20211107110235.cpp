#include <iostream>
#include <string>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int main() {
  string str;
  int cnt = 1;

  __init();

  getline(cin, str);

  for(int i = 0; i < str.size(); i++) {
    if(str[i] == ' ') cnt++;
  }
  cout << cnt;
}