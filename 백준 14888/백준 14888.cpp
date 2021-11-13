#include <iostream>
using namespace std;

int num[12]{};
int oper[5]{};
int visited[12]{};
int N;
int P = 1;

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void backTracking(int cnt) {	
	if (cnt == N) {
		int ans = num[1];
		for (int i = 1; i < N; i++) {
			if (visited[i] != 0) {
				switch (visited[i]) {
				case 1:
					ans += num[i + 1];
					break;
				case 2:
					ans -= num[i + 1];
					break;
				case 3:
					ans *= num[i + 1];
					break;
				case 4:
					ans /= num[i + 1];
					break;
				}
			}
		}
		cout << ans << "\n";
		return;
	}

	for (int i = 1; i < N; i++) {
		if (visited[i] == 0) {
			for (int j = 1; j <= 4; j++) {
				if (oper[j] != 0) {
					visited[i] = j;
					oper[j]--;
					backTracking(cnt + 1);
					visited[i] = 0;
					oper[j]++;
				}
			}
		}
	}
}

int main() {

	__init();

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		P *= i;
	}
	for (int i = 1; i <= 4; i++) cin >> oper[i];
	backTracking(1);
}