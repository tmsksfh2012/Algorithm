#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N, tmp, sum = 0;
	int most = -1, most_num = 0;
	int arr[8001]{ 0 };
	bool first = false;
	vector<int> v{};

	__init();

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		sum += tmp;
		v.push_back(tmp);
		arr[tmp + 4000]++;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= 8000; i++) {
		if (arr[i] == 0) continue;
		else if (arr[i] == most && first) {
			most_num = i - 4000;
			first = false;
		}
		else if (arr[i] > most) {
			most_num = i - 4000;
			most = arr[i];
			first = true;
		}
	}
	if (round((sum * 1.0) / N) == -0)
		cout << 0 << "\n";
	else 
		cout << round((sum * 1.0) / N) << "\n";
	cout << v[N / 2] << "\n";
	cout << most_num << "\n";
	cout << v[N - 1] - v[0];
}