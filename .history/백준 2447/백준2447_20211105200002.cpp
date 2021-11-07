#include <iostream>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

void DrawingStar(int x, int y, int num) {
  if((x / num)%3 == 1 && (y / num)%3 == 1) {
    cout << " ";
  }
  else {
    cout << "*";
  }
}

int main() {
  int NUM;

  __init();
  
  
  NUM = 9;
  // cin >> NUM;

  for(int i = 0; i < NUM; i++) {
    for(int j = 0; j < NUM; j++)
      DrawingStar(i, j, NUM);
    cout<< "\n";
  }
}