#include <iostream>
#include <string>
#include <map>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, M{};
	map<string, string> m;

	__init();

	cin >> N >> M;

	while (N--) {
		string site{}, pw{};

		cin >> site >> pw;

		m.insert({ site, pw });
	}

	while (M--) {
		string site{};
		
		cin >> site;

		cout << m.find(site)->second << endl;
	}
}