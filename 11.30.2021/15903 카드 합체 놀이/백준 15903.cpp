#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int n{}, m{};
	long long ans{};
	priority_queue<long long> pq;

	__init();

	cin >> n >> m;

	while (n--) {
		int tmp{};
		cin >> tmp;
		pq.push(-tmp);
	}

	while (m--) {
		long long fir_num = pq.top();
		pq.pop();

		long long sec_num = pq.top();
		pq.pop();

		long long sum = fir_num + sec_num;

		pq.push(sum);
		pq.push(sum);
	}

	while(!pq.empty()) {
		ans += -pq.top();
		pq.pop();
	}
	
	cout << ans;
}