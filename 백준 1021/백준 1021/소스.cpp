#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int N, num;

int main() {
	cin >> N >> num;

	int count = 0;

	for (int i = 1; i <= N; i++) dq.push_back(i);

	int Node;
	for (int i = 0; i < num; i++) {
		cin >> Node;

		int index = 0;
		for (int i = 0; i < dq.size(); i++) {
			if (dq.at(i) == Node) {
				index = i;
				break;
			}
		}
		if ((dq.size() - index) > index) {
			while (true) {
				if (dq.front() == Node) {
					dq.pop_front();
					break;
				}
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				count++;
			}
		}
		else {
			while (true) {
				if (dq.front() == Node) {
					dq.pop_front();
					break;
				}
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				count++;
			}
		}
	}
	cout << count;
}