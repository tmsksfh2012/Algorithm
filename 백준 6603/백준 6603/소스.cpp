#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int num;

	while (cin >> num && num != 0) {

		vector<bool> perMat(num, false);
		vector<int> lottoMat(num);

		for (int i = 0; i < num; i++) {
			cin >> lottoMat[i];
		}

		for (int i = 0; i < 6; i++) {
			perMat[i] = true;
		}

		do {
			for (int i = 0; i < num; ++i) {
				if (perMat[i])
					cout << lottoMat[i] << ' ';
			}
			cout << endl;
		} while (prev_permutation(perMat.begin(), perMat.end()));

		cout << endl;
	}
}