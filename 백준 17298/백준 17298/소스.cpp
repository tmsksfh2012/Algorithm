#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int N, i, temp;
	vector <int> v;
	stack <int> s;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	vector <int> ans(v.size(), -1);

	for (i = 0; i < N; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}