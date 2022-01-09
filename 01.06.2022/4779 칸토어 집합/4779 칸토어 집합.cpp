#include <iostream>
#include <queue>
#include <math.h>
#define endl "\n"
using namespace std;

queue<int> q{};

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

void Cantor(int start, int end) {
	if (start + 1 == end)
		q.push(end);
	else {
		Cantor(start, start + (end - start) / 3);
		Cantor(end - (end - start) / 3, end);
	}
}

int main() {
	__init();

	int N{};

	while (cin >> N) {
		int n = pow(3, N);
		Cantor(0, n);
		int idx = 1;
		while (!q.empty()) {
			if (idx == q.front()) {
				cout << "-";
				q.pop();
				idx++;
			}
			else {
				cout << " ";
				idx++;
			}
		}
		cout << endl;
	}
}