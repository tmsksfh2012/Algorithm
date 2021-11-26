#include <iostream>
#include <vector>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N;
	vector<pair<pair<int, int>,int>> v;
	
	__init();

	cin >> N;

	for (int i{}; i < N; i++) {
		int weigh, heigh;
		cin >> weigh >> heigh;
		v.push_back({ { weigh, heigh }, 1 });
	}

	for (int i{}; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second) v[i].second++;
			if (v[i].first.first > v[j].first.first && v[i].first.second > v[j].first.second) v[j].second++;
		}

	for (auto i : v) cout << i.second << " ";
}