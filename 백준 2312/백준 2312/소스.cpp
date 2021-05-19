#include <iostream>
#include <algorithm>
using namespace std;

int T;
int chk[100001] = { 0, };

void chkChk(int chkNum) {

}

void primeNum(int num) {
	for (int i = 2; i <= num; i++) {
		chk[num] = -1;
		if (chk[i] != 0) continue;
		else {
			if (num % i != 0) {
				continue;
			}
			chk[i] = 1;
			for (int j = i * 2; j < num; j += i) {
				if (num % j != 0) continue;
				if (chk[j] != 0) {
					chkChk(j);
				}
				chk[j] = -1;
				chk[i]++;
			}
		}
	}
	for (int i = 2; i < num; i++) {
		if(chk[i] != -1 && chk[i] != 0)
			cout << i << " " << chk[i] << "\n";
	}
}

int main() {
	cin >> T;

	while (T--) {
		int numInput;
		cin >> numInput;
		primeNum(numInput);
		memset(chk, false, sizeof(chk));
	}
}