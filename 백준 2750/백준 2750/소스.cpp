#include <iostream>
#include <algorithm>
using namespace std;

int Mat[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> Mat[i];

	sort(Mat, Mat + N);

	for (int i = 0; i < N; i++) cout << Mat[i]<<'\n';
}