#include<iostream>
#include<stack>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	string ans{};
	int n{}, x{}, max{};
	stack<int> s;

	__init();

	cin >> n;

	while (n--) {
		cin >> x;
		if (x > max) {
			for (int i = max + 1; i <= x; i++) {
				s.push(i);
				ans += '+';
			}
		}
		else
			if (s.top() != x) {
				cout << "NO";
				return 0;
			}
		s.pop();
		ans += '-';
		if (max < x) max = x;
	}
	for (auto c : ans)
		cout << c << endl;

	return 0;
}