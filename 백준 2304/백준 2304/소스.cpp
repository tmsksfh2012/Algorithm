#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int n;

	cin >> n;
	int fir, sec;
	for (int i = 0; i < n; i++) {
		cin >> fir >> sec;
		v.emplace_back(make_pair(fir, sec));
	}

	sort(v.begin(), v.end());

	//¿ÞÂÊ ³ÐÀÌ ±¸ÇÏ±â
	int left_X = v.front().first;
	int left_Y = v.front().second;
	int answer = 0;

	for (int i = 0; i < v.size(); i++) {
		if (left_Y <= v[i].second) {
			answer += (v[i].first - left_X) * left_Y;
			left_Y = v[i].second;
			left_X = v[i].first;
		}
	}
	//¿À¸¥ÂÊ ³ÐÀÌ ±¸ÇÏ±â
	int right_X = v.back().first;
	int right_Y = v.back().second;

	for (int i = v.size() - 1; i > -1; i--) {
		if (right_Y < v[i].second) {
			answer += (right_X - v[i].first) * right_Y;
			right_Y = v[i].second;
			right_X = v[i].first;
		}
	}
	//°¡Àå ³ôÀº ±âµÕÀÇ ³ÐÀÌ == left_Y * 1 == right_Y * 1
	cout << answer + left_Y << endl;
}