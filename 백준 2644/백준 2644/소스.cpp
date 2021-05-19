#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, LINE;
int start, goal;
vector<int>vec[101];
int cache[101];

int bfs() {
	queue<int> q;

	q.push(start);

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		if (curNode == goal) return cache[goal];

		for (int i = 0; i < vec[curNode].size(); i++) {
			int next = vec[curNode][i];

			if (cache[next] == 0) {
				q.push(next);
				cache[next] = cache[curNode] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> start >> goal >> LINE;

	int fir, sec;
	for (int i = 0; i < LINE; i++) {
		cin >> fir >> sec;
		vec[fir].push_back(sec);
		vec[sec].push_back(fir);
	}

	cout << bfs();
}