#include <iostream>
#include <string>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int main() {
  string str;
  int cnt = 0;

  __init();

  getline(cin, str);
  cout << str.size();

  for(int i = 0; i < str.size(); i++) {
    if(str[i] == ' ') cnt++;
    cout << str[i] << " ";
  }
  cout << cnt;
}