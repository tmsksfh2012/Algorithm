#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

void Factorization(int num) {
  while(num/=2) cout << num << "\n";
}

int main() {
  int num;

  __init();

  cin >> num;
  Factorization(num);
}