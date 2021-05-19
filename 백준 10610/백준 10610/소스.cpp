#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int Mat[1000001];
int odd;
bool isZero = false;

bool desc(int fir, int sec) {
	return fir > sec;
}

int main() {
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		Mat[i] = str[i] -'0';
		odd += Mat[i];
		if (Mat[i] == 0) isZero = true;
	}
	if (odd % 3 != 0 || !isZero) {
		cout << -1;
		return 0;
	}
	sort(Mat, Mat + str.size(), desc);

	for (int i = 0; i < str.size(); i++) {
		cout << Mat[i];
	}
}