#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int dp[4001][4001], ans;

int main() {
	cin >> str1 >> str2;

	for(int i = 0; i < str1.size(); i++)
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) {
				if (str1[i] == str2[j]) dp[i][j] = 1;
				continue;
			}
			if (str1[i] == str2[j])dp[i][j] = dp[i - 1][j - 1] + 1;

			ans = max(ans, dp[i][j]);
		}

	cout << ans;
}