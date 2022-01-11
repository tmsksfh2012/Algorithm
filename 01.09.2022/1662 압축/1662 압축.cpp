#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool visit[51]{};

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

int dfs(string& s, int idx) {
	int cnt = 0;
	for (int i = idx; i < s.size(); i++) {
		if (s[i] == '(' && !visit[i]) {
			visit[i] = true;
			int num = s[i - 1] - '0';
			cnt--;
			cnt += num * dfs(s, i + 1);
		}
		else if (s[i] == ')' && !visit[i]) {
			visit[i] = true;
			return cnt;
		}
		else if (!visit[i]) {
			visit[i] = true;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	__init();

	string str{};

	cin >> str;

	cout << dfs(str, 0);
}