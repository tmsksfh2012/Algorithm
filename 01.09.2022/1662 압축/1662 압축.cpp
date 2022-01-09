#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str{};

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	__init();

	stack<string> num{};
	stack<char> bracket{};

	cin >> str;

	for (int i = str.size() - 1; i >= 0; i--) {
		// 괄호 넣는 부분
		if (str[i] == ')') {
			bracket.push(str[i]);
		}
		else if (str[i] == '(') {
			bracket.push(str[i]);
		}
		// 숫자 넣는 부분
		else {
			string tmp{};

			if (bracket.empty()) {
				tmp.push_back(str[i]);
				while (!num.empty()) {
					tmp += num.top();
					num.pop();
				}
				num.push(tmp);
			}

			else if (bracket.top() == ')') {
				tmp.push_back(str[i]);
				num.push(tmp);
			}

			// 숫자 반복 부분
			else if (bracket.top() == '(') {
				bracket.pop();
				bracket.pop();
				int cnt = str[i] - '0';
				while (!num.empty()) {
					tmp += num.top();
					num.pop();
				}
				for (int i{}; i < cnt; i++) {
					num.push(tmp);
				}
			}
		}
	}
	string ans = num.top();
	num.pop();
	cout << ans.size();
}