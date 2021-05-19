#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> stack_str;
	stack<char> New_stack_str;
	stack<char> ans;
	int num;

	string str;
	cin >> str;

	while (!str.empty()) {
		stack_str.push(str[0]);
		str.erase(0,1);
	}
	cin >> num;
	char fir, sec;
	for (int i = 0; i < num; i++) {
		cin >> fir;
		if (fir == 'P') {
			cin >> sec;
			stack_str.push(sec);
		}
		else if (fir == 'L' && !stack_str.empty()) {
			New_stack_str.push(stack_str.top());
			stack_str.pop();
		}
		else if (fir == 'D' && !New_stack_str.empty()) {
			stack_str.push(New_stack_str.top());
			New_stack_str.pop();
		}
		else if (fir == 'B' && !stack_str.empty()) {
			stack_str.pop();
		}
	}
	
	while (!stack_str.empty()) {
		ans.push(stack_str.top());
		stack_str.pop();
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	while (!New_stack_str.empty()) {
		cout << New_stack_str.top();
		New_stack_str.pop();
	}
}