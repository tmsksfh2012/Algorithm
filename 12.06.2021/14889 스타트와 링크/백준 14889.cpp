#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

bool chk[21]{ false };
int arr[21][21]{};
int N{}, MIN = 987654321;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void BackTracking(int cnt, int pos) {
	if (cnt >= N / 2) {
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (chk[i] && chk[j]) start += arr[i][j];
				if (!chk[i] && !chk[j]) link += arr[i][j];
			}
		}

		int temp = abs(start - link);
		MIN = MIN > temp ? temp : MIN;

	}

	else {
		for (int i = pos; i < N; i++) {
			chk[i] = true;
			BackTracking(cnt + 1, i + 1);
			chk[i] = false;
		}
	}
}

int main() {
	__init();

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	BackTracking(0, 1);

	cout << MIN;
}