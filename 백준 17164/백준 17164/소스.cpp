#include <iostream>
using namespace std;

int main() {
	int N;
	char C;
	char nextC;
	int maxLen = -1;
	int curlen = 0;

	cin >> N;
	cin >> C;
	if (N == 1) {
		cout << N;
	}
	else {
		N--;
		curlen++;
		while (N > 0) {
			cin >> nextC;
			if (C == nextC) {
				if (curlen > maxLen) {
					maxLen = curlen;
					curlen = 1;
				}
				else {
					curlen = 1;
				}
			}
			else if (((C == 'R') && (nextC == 'V')) || ((C == 'V') && (nextC == 'R'))
				|| ((C == 'B') && (nextC == 'V')) || ((C == 'V') && (nextC == 'B'))) {
				if (curlen > maxLen) {
					maxLen = curlen;
					curlen = 1;
				}
				else {
					curlen = 1;
				}
			}
			else {
				curlen++;
			}
			N--;
			C = nextC;
		}
		if (curlen > maxLen) {
			maxLen = curlen;
		}
		cout << maxLen;
	}
	return 0;
}