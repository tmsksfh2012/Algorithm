#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, M;
	vector<string> listen;
	vector<string> ans;

	cin >> N >> M;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		listen.push_back(tmp);
	}
	sort(listen.begin(), listen.end());
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (binary_search(listen.begin(), listen.end(), tmp)) ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}