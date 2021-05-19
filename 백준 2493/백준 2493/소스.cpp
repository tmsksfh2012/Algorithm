#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
	int N;
	stack<pair<int, int>> stackNum;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		scanf("%d", &tmp);

		while (!stackNum.empty()) {
			if (stackNum.top().second > tmp) {
				printf("%d ", stackNum.top().first);
				break;
			}
			stackNum.pop();
		}
		if (stackNum.empty()) printf("0 ");

		stackNum.push(make_pair(i + 1, tmp));
	}
}