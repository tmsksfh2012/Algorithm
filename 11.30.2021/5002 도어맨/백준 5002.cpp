#include <iostream>
#include <string>
#include <stack>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	string str{};
	stack<char> s;
	int X{}, cnt_m{}, cnt_w{};

	__init();

	cin >> X >> str;

	for (int i{}; i < str.size(); i++) {
		char c = str[i];
		c == 'M' ? cnt_m++ : cnt_w++;

		if (s.empty())
			s.emplace(c);
		else {
			if (abs(cnt_m - cnt_w) <= X) {
				s.emplace(c);
			}
			else {
				char now = c;
				char tmp = str[++i];

				tmp == 'M' ? cnt_m++ : cnt_w++;

				if (abs(cnt_m - cnt_w) <= X) {
					s.emplace(tmp);
					s.emplace(now);
				}
				else
					break;
			}
		}
	}
	cout << s.size();
}