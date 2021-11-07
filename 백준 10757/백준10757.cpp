#include <iostream>
#include <string>
#include <stack>
using namespace std;

void __init() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main() {
  string fir, sec, tmp;
  stack<int> stk;
  int num1[10001], num2[10001];

  __init();

  cin >> fir >> sec;
  if(fir.size() < sec.size()) {
    tmp = fir;
    fir = sec;
    sec = tmp;
  }

  for(int i = 0; i < fir.size(); i++)
    num1[i + 1] = fir[i] - '0';

  for(int i = 0; i < sec.size(); i++)
    num2[i + 1 + (fir.size() - sec.size())] = sec[i] - '0';

  for(int i = fir.size(); i > 0; i--){
    int sum = num1[i] + num2[i];
    if(sum >= 10) {
      num1[i-1]++;
      sum -= 10;
    }
    stk.push(sum);
  }

  if(num1[0] != 0) cout << num1[0];

  while(!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
}