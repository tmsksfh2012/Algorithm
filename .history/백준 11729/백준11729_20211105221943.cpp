#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

queue<pair<int,int>> q;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

void Hanoi(int start, int end, int blank, int cnt) {
  if(cnt == 1) {
    cout << start << " " << end << "\n";
    return;
  }
  Hanoi(start, blank, end, cnt-1);
  Hanoi(start, end, blank, 1);
  Hanoi(blank, end, start, cnt-1);
}

int main() {
  int num;

  __init();

  cin >> num;

  cout << pow(2,num) - 1 << "\n";
  Hanoi(1,3,2,num);
  
}