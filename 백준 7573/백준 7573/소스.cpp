#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int N, I, M, ans;
vector <pair<int, int>> map;

void fc(int y, int x, int netY, int netX) {
	int total = 0;

	for (int i = 0; i < M; i++) {
		int fishY = map[i].first;
		int fishX = map[i].second;
		if (y <= fishY && fishY <= y + netY && x <= fishX && fishX <= x + netX) total++;

		ans = max(ans, total);
	}
}

int main() {
	stack<pair<int, int>> st;

	cin >> N >> I >> M;

	int y, x;

	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		map.emplace_back(y, x);
		st.push({ y,x });
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			for (int k = 1; k < I / 2; k++)
				fc(map[i].first, map[j].second, k, I / 2 - k);

	cout << ans;
}