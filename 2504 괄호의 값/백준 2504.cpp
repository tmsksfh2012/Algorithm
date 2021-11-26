#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<int> st;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int getNextSum(char next) {
	int sum = 0;
	char open = next == ')' ? '(' : '[';
	char impossibleOpen = next == ')' ? '[' : '(';

	while (!st.empty()) {
		int prev = st.top();
		st.pop();
		if (prev == open)
			return sum == 0 ? (next == ')' ? -2 : -3) : (next == ')' ? sum * (-2) : sum * (-3));

		if (prev == impossibleOpen)  return -1;

		sum -= prev;
	}

	return -1;
}

int main() {
	int sum{}, open{};

	__init();

	cin >> str;

	for (auto i : str) {
		switch (i) {
		case  '(':
		case '[':
			st.push(i);
			break;
		case ')':
		case ']':
			int s = getNextSum(i);
			if (s == -1) {
				cout << 0;
				return 0;
			}
			st.push(s);
			break;
		}
	}
	int ans = 0;

	while (!st.empty()) {
		if (st.top() == '[' || st.top() == ']' || st.top() == '(' || st.top() == ')') {
			cout << 0;
			return 0;
		}
		ans -= st.top();
		st.pop();
	}

	cout << ans;
}