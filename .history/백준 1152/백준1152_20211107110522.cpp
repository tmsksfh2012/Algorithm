#include <iostream>
using namespace std;

int main(){
    string str;
    int counter = 0;
    while (cin>>str)
    {
      cout << str << " ";
      counter +=1;
    }
    cout<<counter;
    return 0;
}