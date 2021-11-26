#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool compare(pair<pair<int,int>,int>a, pair<pair<int,int>,int> b) {
	if (a.first.first == b.first.first)
		return a.second > b.second;
	else
		return a.first.first > b.first.first;
}

int main() {
	int N;
	vector<vector<int>>v;
	vector<pair<pair<int, int>, int>> ans;


	__init();

	cin >> N;

	for (int i{}; i < N; i++) {
		vector<int> num;
		for (int j{}; j < 5; j++) {
			int tmp;
			cin >> tmp;
			num.push_back(tmp);
		}
		v.push_back(num);
	}

	for (int i{}; i < N; i++) {
		ans.push_back({ {0,0},i + 1 });
		for (int j{}; j < 5; j++) {
			for (int o = j + 1; o < 5; o++)
				for (int p = o + 1; p < 5; p++) {
					int sum = v[i][j];
					int top = v[i][j];

					top = top > v[i][o] ? top : v[i][o];
					top = top > v[i][p] ? top : v[i][p];
					sum += v[i][o] + v[i][p];
					sum %= 10;
					if (ans[i].first.first < sum) {
						ans[i].first.first = sum;
						ans[i].first.second = top;
					}
				}
		}
	}

	sort(ans.begin(), ans.end(), compare);

	cout << ans[0].second;
}