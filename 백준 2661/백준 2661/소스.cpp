#include <iostream>
#include <string>
using namespace std;

int N;
string str;

void permutation(char c, int cnt) {
	if (cnt - 1 == N) {
		cout << str;
		exit(0);
	}
	str += c;
	for (int i = 1; i <= cnt / 2; i++) {
		string tmp1 = str.substr(cnt - i, i);
		string tmp2 = str.substr(cnt - i * 2, i);

		if (tmp1 == tmp2) {
			str.erase(cnt - 1);
			return;
		}
	}
	for (int i = 1; i <= 3; i++) permutation(i + '0', cnt + 1);

	str.erase(cnt - 1);
}

int main() {
	cin >> N;

	for (int i = 1; i <= 3; i++) {
		permutation(i + '0', 1);
	}
}