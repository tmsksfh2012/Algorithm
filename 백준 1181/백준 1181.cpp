#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

struct Compare {
	bool operator() (const string& a, const string& b)
		const {
		if (a.size() == b.size())
			return a < b;
		else 
			return a.size() < b.size();
	}
};

int main() {
	int N;
	string input;
	set<string, Compare> s;

	__init();

	cin >> N;

	while (N--) {
		cin >> input;
		s.insert(input);
	}

	for (auto str : s) cout << str << "\n";
}