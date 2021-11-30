#include <iostream>
#include <stack>
#include <string>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	string str{};
	stack<char> s;

	__init();

	cin >> str;

	for (auto c : str) {
		if (s.empty())
			s.emplace(c);
		else {
			if (c == ')' && s.top() == '(')
				s.pop();
			else
				s.emplace(c);
		}
	}

	cout << s.size();
}