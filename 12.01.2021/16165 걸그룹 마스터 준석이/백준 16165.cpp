#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

int main() {
	int N{}, M{};
	map<string, vector<string>> girlGroup{};
	map<string, string> girlName{};

	__init();

	cin >> N >> M;

	while (N--) {
		string teamName{};
		int teamSize{};
		cin >> teamName >> teamSize;

		vector<string> names{};

		while (teamSize--) {
			string name{};

			cin >> name;

			names.push_back(name);
			girlName.insert({ name, teamName });
		}

		sort(names.begin(), names.end());
		girlGroup.insert({ teamName, names });
	}

	while (M--) {
		string name{};
		int num{};

		cin >> name >> num;

		switch (num) {
		case 0:
			for (auto p : girlGroup[name])
				cout << p << endl;
			break;
		case 1:
			cout << girlName[name] << endl;
			break;
		}
	}
}