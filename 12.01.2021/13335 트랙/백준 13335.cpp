#include <iostream>
#include <queue>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int n{}, w{}, L{}, cnt{}, wt{};
	queue<int> q;
	queue<int> firWt;

	__init();

	cin >> n >> w >> L;

	for (int i{}; i < n; i++) {
		int num{};
		cin >> num;
		q.push(num);
	}

	while (!q.empty()) {
		while (!q.empty()) {
			if (firWt.size() == w) {
				wt -= firWt.front();
				firWt.pop();
			}
			if (wt + q.front() <= L) break;
			firWt.push(0);
			cnt++;
		}
		firWt.push(q.front());
		wt += q.front();
		cnt++;
		q.pop();
	}
	cout << cnt + w;
}