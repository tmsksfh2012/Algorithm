#include <iostream>
#include <stack>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int K;
	long long sum{};
	stack<int> s;

	__init();

	cin >> K;

	while (K--) {
		int tmp;

		cin >> tmp;
		if (tmp == 0) {
			sum -= s.top();
			s.pop();
		}
		else {
			s.push(tmp);
			sum += tmp;
		}
	}

	cout << sum;
}