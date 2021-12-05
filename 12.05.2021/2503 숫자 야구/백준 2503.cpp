#include <iostream>
#include <string>
using namespace std;

bool arr[1001]{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

bool chk(string iter, string num, int strike, int ball) {
	int stCnt{}, bCnt{};
	if (iter[0] == '0' || iter[1] == '0' || iter[2] == '0' || iter[0] == iter[1] || iter[1] == iter[2] || iter[0] == iter[2])
		return true;

	if (iter[0] == num[0])
		stCnt++;
	if (iter[1] == num[1])
		stCnt++;
	if (iter[2] == num[2])
		stCnt++;

	if (iter[0] == num[1] || iter[0] == num[2])
		bCnt++;
	if (iter[1] == num[0] || iter[1] == num[2])
		bCnt++;
	if (iter[2] == num[0] || iter[2] == num[1])
		bCnt++;

	if (stCnt == strike && bCnt == ball)
		return false;
	else
		return true;
}

int main() {
	__init();

	int N{}, strike{}, ball{}, ans{};

	string num{};

	cin >> N;

	while (N--) {
		cin >> num >> strike >> ball;

		for (int i = 123; i <= 987; i++) {
			if (!arr[i]) {
				arr[i] = chk(to_string(i), num, strike, ball);
			}
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (!arr[i]) {
			ans++;
		}
	}

	cout << ans;
}