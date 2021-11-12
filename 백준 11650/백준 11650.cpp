#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int num, fir, sec;
	vector<pair<int,int>> vc;
	
	__init();

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> fir >> sec;
		vc.push_back({ fir,sec });
	}
	sort(vc.begin(), vc.end());

	for (int i = 0; i < num; i++) cout << vc[i].first << " " << vc[i].second << "\n";
}