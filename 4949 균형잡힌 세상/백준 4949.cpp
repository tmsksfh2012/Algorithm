#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool isOpenBracket(char c) {
	if (c == '(' || c == '[')
		return true;
	else
		return false;
}

bool isCloseBracket(char c) {
	if (c == ')' || c == ']')
		return true;
	else
		return false;
}

bool isPairBracket(char c1, char c2) {
	char close = c1 == '(' ? ')' : ']';

	return close == c2;
}

int main() {

	while (true) {
		string str;
		vector<char> v;
		stack<char> s;
		bool end{};

		__init();

		getline(cin, str);

		if (str == ".")
			break;

		for (auto c : str) {
			if (isOpenBracket(c) || isCloseBracket(c))
				v.push_back(c);
		}

		for (auto c : v) {
			if (isOpenBracket(c))
				s.push(c);
			else {
				if (!s.empty() && isPairBracket(s.top(), c))
					s.pop();
				else {
					cout << "no" << endl;
					end = true;
					break;
				}
			}
		}
		if (!end) {
			if (s.empty())
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
}