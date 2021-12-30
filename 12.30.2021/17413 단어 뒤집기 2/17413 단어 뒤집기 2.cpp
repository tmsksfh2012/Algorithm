#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char>& s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	string str{};

	getline(cin, str);

	stack<char> st{};
	bool flag = false;
	for (auto tmp : str) {
		if (tmp == '<') {
			print(st);
			flag = true;
			cout << tmp;
		}
		else if (tmp == '>') {
			flag = false;
			cout << tmp;
		}
		else if (flag)
			cout << tmp;

		else {
			if (tmp == ' ') {
				print(st);
				cout << tmp;
			}
			else
				st.push(tmp);
		}		
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}