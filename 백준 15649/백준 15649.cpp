#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[9]{};
bool visited[9]{};

void __init() {
	cin.tie(0);
	ios::sync_with_stdio(0);
}

void backTracking(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[cnt] = i;
				backTracking(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	__init();

	cin >> N >> M;

	backTracking(0);
}