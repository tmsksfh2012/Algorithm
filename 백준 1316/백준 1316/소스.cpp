#include <iostream>
#include <string>
using namespace std;

bool check(string str) {
	bool alphabet[26] = { 0, };

	char con = str[0];
	for (int tmp = 0; tmp < str.size(); tmp++) {
		if (!alphabet[str[tmp]-'a']) {
			con = str[tmp];
			alphabet[str[tmp] - 'a'] = true;
		}
		else if (con == str[tmp]) {
			con = str[tmp];
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int N, cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;

		cin >> tmp;
		if (check(tmp)) cnt++;
	}
	cout << cnt;
}