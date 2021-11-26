#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{};

	__init();

	cin >> N;

	while (N--) {
		string str;
		stack<char> s;

		cin >> str;

		for (auto c : str) {
			if (s.empty())
				s.push(c);

			else {
				if (c == ')' && s.top() == '(') {
					s.pop();
				}
				else
					s.push(c);
			}
		}

		if (s.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}