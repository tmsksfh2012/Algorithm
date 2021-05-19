#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<char> st;
	int res = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') st.push(str[i]);
		else {
			st.pop();
			if (str[i - 1] == '(') res += st.size();
			else res++;
		}
	}
		cout << res;
}