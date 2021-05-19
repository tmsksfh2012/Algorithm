#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec;
bool Mat[10];

void permutation() {
	if (vec.size() == N) {
		for (auto tmp : vec) {
			cout << tmp << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 1; i <= N; i++) {
			if (Mat[i] == true) continue;
			Mat[i] = true;
			vec.push_back(i);
			permutation();
			vec.pop_back();
			Mat[i] = false;
		}
	}
}

int main() {
	cin >> N;
	permutation();
}