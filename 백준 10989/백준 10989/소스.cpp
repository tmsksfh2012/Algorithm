#include <iostream>
#include <algorithm>
using namespace std;

int Mat[10000001];

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Mat[i];
	}

	sort(Mat, Mat + N);

	for (int j = 0; j < N; j++) {
		cout << Mat[j] << endl;
	}
}