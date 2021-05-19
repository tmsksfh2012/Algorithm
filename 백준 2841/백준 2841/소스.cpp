#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s[7];
	int N, P;
	int res = 0;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		pair<int, int>tmp;
		cin >> tmp.first >> tmp.second;

		if (s[tmp.first].empty()) {
			res++;
			s[tmp.first].push(tmp.second);
		}
		else {
			if (tmp.second > s[tmp.first].top()) {
				s[tmp.first].push(tmp.second);
				res++;
			}
			else if (tmp.second == s[tmp.first].top()) continue;
			else {
				while (!s[tmp.first].empty() && tmp.second < s[tmp.first].top()) {
					s[tmp.first].pop();
					res++;
				}
				if (!s[tmp.first].empty() && s[tmp.first].top() == tmp.second) continue;
				s[tmp.first].push(tmp.second);
				res++;
			}
		}
	}
	cout << res;
}