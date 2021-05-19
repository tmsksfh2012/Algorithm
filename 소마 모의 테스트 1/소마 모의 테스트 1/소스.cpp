#include <iostream>
using namespace std;

int main() {
	int x = 0;

	char curC;
	char nextC;

	while (true) {
		curC = cin.get();
		if (curC == '(') {
			x--;
		}
		else if (curC == ')') {
			x++;
		}
		else if (curC == '\n') {
			break;
		}
	}
	if (x >= 0) {
		printf("YES");
	}
	else if (x < 0) {
		printf("NO");
	}

	return 0;
}