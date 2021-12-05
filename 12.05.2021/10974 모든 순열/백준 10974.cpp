#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int N{};
bool chk[9]{};
vector<int> v;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void permutation() {
	if (v.size() == N){
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!chk[i]) {
				chk[i] = true;
				v.push_back(i);
				permutation();
				v.pop_back();
				chk[i] = false;
			}
		}
	}
}

int main() {
	__init();
	
	cin >> N;
	
	permutation();

}