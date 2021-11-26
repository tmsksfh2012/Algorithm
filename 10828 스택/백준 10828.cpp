#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{};
	string str{};
	int num{};
	stack<int> s{};

	__init();

	cin >> N;

	while (N--) {
		cin >> str;
		if (str.compare("push") == 0) {
			cin >> num;
			s.push(num);
		}
		else if (str.compare("pop") == 0) {
			if (s.empty())
				cout << -1 << endl;

			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (str.compare("empty") == 0) {
			int ans = s.empty() ? 1 : 0;
			cout << ans << endl;
		}
		else if (str.compare("size") == 0) {
			cout << s.size() << endl;
		}
		else if (str.compare("top") == 0) {
			if (s.empty())
				cout << -1 << endl;

			else {
				cout << s.top() << endl;
			}
		}
	}
}