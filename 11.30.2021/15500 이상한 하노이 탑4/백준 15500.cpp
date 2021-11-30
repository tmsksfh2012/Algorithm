#include <iostream>
#include <stack>
#include <vector>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, fir{}, sec{}, thr{};
	stack<int> s1, s2;
	vector<pair<int, int>> ans;
	bool flag = true;

	__init();

	cin >> N;

	for (int i{}; i < N; i++) {
		int num{};
		cin >> num;
		s1.emplace(num);
	}
	int idx = N;

	while (idx > 0) {
		if (flag) {
			while (!s1.empty()) {
				if (s1.top() == idx) {
					ans.push_back({ 1, 3 });
					s1.pop();
					idx--;
				}
				else {
					ans.push_back({ 1,2 });
					s2.push(s1.top());
					s1.pop();
				}
			}
			flag = false;
		}
		else {
			while (!s2.empty()) {
				if (s2.top() == idx) {
					ans.push_back({ 2, 3 });
					s2.pop();
					idx--;
				}
				else {
					ans.push_back({ 2, 1 });
					s1.push(s2.top());
					s2.pop();
				}
			}
			flag = true;
		}
	}

	cout << ans.size() << endl;

	for (auto pair : ans) {
		cout << pair.first << " " << pair.second << endl;
	}
}