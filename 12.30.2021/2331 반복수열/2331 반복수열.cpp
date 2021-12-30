#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int A{}, P{}, idx{};
vector<int> v;

int main() {
	cin >> A >> P;

	v.push_back(A);

	bool flag = true;
	while (flag) {
		string num = to_string(v[v.size() - 1]);
		int next_num{};
		for (auto ch : num) {
			next_num += pow(ch - '0', P);
		}
		for (int i{}; i < v.size(); i++) {
			if (v[i] == next_num) {
				idx = i;
				flag = false;
				break;
			}
		}
		v.push_back(next_num);
	}

	cout << idx;
}