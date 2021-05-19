#include<iostream>
#include<stack>
using namespace std;

char sol[200050];
int solptr = 0;
int n, x, max = 0;

int main() {
	cin >> n;

	stack<int> s;

	while (n--) {
		cin >> x;
		if (x > max) {
			for (int i = max + 1; i <= x; i++) {
				s.push(i);
				sol[solptr++] = '+';
			}
		}
		else
			if (s.top() != x) {
				cout << "NO";
				return 0;
			}
		s.pop();
		sol[solptr++] = '-';
		if (max < x) max = x;
	}
	for (int i = 0; i < solptr; i++) cout << sol[i] << "\n";
}
