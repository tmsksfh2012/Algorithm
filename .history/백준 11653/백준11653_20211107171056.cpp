#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

void Factorization(int num) {
  for(int i = 2; i*i <= num; i ++) {
    while(num % i == 0) {
      cout << i << "\n";
      num /= i;
    }
  }
}

int main() {
  int num;

  __init();

  cin >> num;
  Factorization(num);
}