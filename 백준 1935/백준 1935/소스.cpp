#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<double> double_stack;
string str;
int alpha[27];

int main() {
	int num;

	cin >> num;
	cin >> str;

	for (int i = 0; i < num; i++) cin >> alpha[i];

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && 'Z' >= str[i]) {
			double_stack.push(alpha[str[i] - 'A']);;
		}
		else {
			double fir = double_stack.top();
			double_stack.pop();
			double sec = double_stack.top();
			double_stack.pop();
			if ('*' == str[i]) {
				double_stack.push(fir * sec);
			}
			else if ('/' == str[i]) {
				double_stack.push(sec / fir);
			}
			else if ('+' == str[i]) {
				double_stack.push(fir + sec);
			}
			else if ('-' == str[i]) {
				double_stack.push(sec - fir);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << double_stack.top();
}