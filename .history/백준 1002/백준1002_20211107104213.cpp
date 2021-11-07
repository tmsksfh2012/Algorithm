#include <iostream>
#include <math.h>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(0);
}

int DrawingPoint(int r1, int r2, double d) {
  if(r2 + r1 == d) return 1;
  else if(r1 + r2 > d) {
    // 2point
    if(r2 > r1 ? (r2 - r1 < d) : (r1 - r2 < d)) return 2;
    // 1point
    if(r2 > r1 ? (r2 - r1 == d) : (r1 - r2 == d)) return 1;
    // 0point
    if(r2 > r1 ? (r2 - r1 > d) : (r1 - r2 > d)) return 0;
  }
  return 0;
}

int main() {
  int tk;
  int x1,y1,r1;
  int x2,y2,r2;
  double d;

  __init();

  cin >> tk;

  while(tk--) {
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if((x1 == x2) && (y1 == y2) && (r1 == r2)) {
      cout << -1 << "\n";
      continue;
    }
    d = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
    cout << DrawingPoint(r1, r2, d) << "\n";
  }
}