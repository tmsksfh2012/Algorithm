#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int main() {
  char str;

  __init();

  cin >> str;
  cout << (int)str;
}