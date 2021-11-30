#include <iostream>
#include <string>
#include <deque>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{};

	deque<int> dq;

	__init();

	cin >> N;

	while (N--) {
		string control{};
		int num{};

		cin >> control;
		if (control.compare("push_front") == 0) {
			cin >> num;
			dq.push_front(num);
		}
		else if (control.compare("push_back") == 0) {
			cin >> num;
			dq.push_back(num);
		}
		else if (control.compare("pop_front") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (control.compare("pop_back") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (control.compare("front") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else cout << dq.front() << endl;
		}
		else if (control.compare("back") == 0)
			if (dq.empty())
				cout << -1 << endl;
			else cout << dq.back() << endl;

		else if (control.compare("size") == 0)
			cout << dq.size() << endl;

		else if (control.compare("empty") == 0) {
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
}