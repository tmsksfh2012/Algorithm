#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N;
priority_queue<int> pqL;
priority_queue<int, vector<int>, greater<int>> pqR;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int tmp;
	while (N--) {
		cin >> tmp;

		if (pqL.empty()) pqL.push(tmp);

		else if (pqR.empty()) {
			if (pqL.top() >= tmp) {
				pqR.push(pqL.top());
				pqL.pop();
				pqL.push(tmp);
			}
			else pqR.push(tmp);
		}
		
		else if (pqR.size() == pqL.size()) {
			if (pqR.top() <= tmp) {
				pqL.push(pqR.top());
				pqR.pop();
				pqR.push(tmp);
			}
		
			else pqL.push(tmp);
		}

		else if (pqR.size() < pqL.size()) {
			if (pqL.top() >= tmp) {
				pqR.push(pqL.top());
				pqL.pop();
				pqL.push(tmp);
			}
			else pqR.push(tmp);
		}
		cout << pqL.top() << "\n";
	}
}