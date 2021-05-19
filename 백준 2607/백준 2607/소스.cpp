#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, ans;
string Mat[101];
int alpha[101][26];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
 		cin >> Mat[i];
		for (int j = 0; j < Mat[i].size(); j++) 
			alpha[i][Mat[i][j] - 'A']++;
	}

	for (int i = 1; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < 26; j++) {
			if (alpha[0][j] != alpha[i][j]) {
				cnt += abs(alpha[0][j] - alpha[i][j]);
			}
		}
		if (cnt == 0) ans++;
		else if (cnt == 1) ans++;
		else if (cnt == 2 && Mat[0].size() == Mat[i].size()) ans++;
	}

	cout << ans;
}