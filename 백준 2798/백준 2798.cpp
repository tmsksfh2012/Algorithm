#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N, M, tmp;
	vector<int> num;
	vector<int> sum;

	__init();

	cin >> N >> M;

	for (int i{}; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}

	for (auto i : num)
		for(auto j : num)
			for (auto o : num) {
				if (i == j || i == o || j == o) continue;
				else {
					tmp = i + j + o;
					if (tmp > M) continue;
					else sum.push_back(tmp);
				}
			}

	sort(sum.begin(), sum.end(), greater<>());

	cout << sum[0];
}