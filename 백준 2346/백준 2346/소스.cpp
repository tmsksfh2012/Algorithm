#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N;
	deque<pair<int, int>> dq;
	cin >> N;

	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		dq.push_back(make_pair(tmp, i));
	}

	int value, index;
	while(dq.size() > 1) {

		value = dq.front().first;
		index = dq.front().second;
		// value < 0 이면 pop하고 push_first
		if (value < 0) {
			tmp = -value;
			cout << dq.front().second << " ";
			dq.pop_front();
			for (int j = 0; j < tmp;j++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		// value > 0 이면 push_back하고 pop
		// 위 과정이 그냥 pop하고 value - 1 만큼 진행하는 것과 같음
		else {
			tmp = value;
			cout << dq.front().second << " ";
			dq.pop_front();
			for (int j = 0; j < tmp - 1; j++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
	}
	cout << dq.front().second;
}