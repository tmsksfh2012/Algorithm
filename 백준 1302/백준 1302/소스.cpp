#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
int main() {
	cin >> n;
	string s;
	map<string, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s]++;
	}
	pair<string, int> max_num;
	for (auto a : mp) {
		if (max_num.second < a.second) max_num = a;
	}

	cout << max_num.first;
}
