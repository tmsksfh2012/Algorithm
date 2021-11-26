#include <iostream>
#include <vector>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N, M, cnt{};
	bool arr[201][201] = { 0, };

	__init();

	cin >> N >> M;

	for (int i{}; i < M; i++) {
		int fir, sec;

		cin >> fir >> sec;
		arr[fir][sec] = true;
		arr[sec][fir] = true;
	}

	for (int i = 1; i <= N; i++)
		for(int j = i + 1; j <= N; j++)
			for (int o = j + 1; o <= N; o++) {
				if (arr[i][j] || arr[i][o] || arr[j][o])
					continue;
				else
					cnt++;
			}

	cout << cnt;
}