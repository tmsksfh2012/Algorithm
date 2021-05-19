#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

int n, m, ans;
bool chk[501] = { 0 };
deque<pair<int, int>> dq;

int main() {
	cin >> n >> m;
	
	vector<vector<int>> mat(n + 1);

	int tmp1, tmp2;
	for (int i = 1; i <= m; i++) {
		cin >> tmp1 >> tmp2;
		mat[tmp1].emplace_back(tmp2);
		mat[tmp2].emplace_back(tmp1);
	}
	
	dq.push_back({ 1, 0 });

	while (!dq.empty()) {
		int num = dq.front().first;
		int cnt = dq.front().second;
		dq.pop_front();

		if (chk[num]) continue;

		ans++;
		chk[num] = true;

		if (cnt == 2) {
			continue;
		}

		for (int i = 0; i < mat[num].size(); i++) {
			int tmp = mat[num][i];
			int tmp_cnt = cnt;

			dq.push_back({ tmp, ++tmp_cnt });
		}
	}
	cout << ans - 1;
}
