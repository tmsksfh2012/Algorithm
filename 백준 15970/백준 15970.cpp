#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	vector<pair<int,int>> v;
	int N, ans{};

	__init();

	cin >> N;

	for (int i{}; i < N; i++) {
		int x, color;

		cin >> x >> color;
		v.push_back({ x, color });
	}

	sort(v.begin(), v.end(), compare);

	for (int i{}; i < N; i++) {
		if (i == 0) ans += (v[i + 1].first - v[i].first);
		else if (i == N - 1) ans += (v[i].first - v[i - 1].first);
		else {
			if (v[i].second != v[i + 1].second)
				ans += v[i].first - v[i - 1].first;

			else if (v[i].second != v[i - 1].second)
				ans += v[i + 1].first - v[i].first;

			else {
				int gap = v[i].first - v[i - 1].first;
				gap = gap > (v[i + 1].first - v[i].first) ? (v[i + 1].first - v[i].first) : gap;
				ans += gap;
			}
		}
	}

	cout << ans;
}