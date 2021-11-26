#include <iostream>
#include <queue>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, K{};
	queue<int> q;

	__init();

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();

		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}