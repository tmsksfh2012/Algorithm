#include <iostream>
using namespace std;

int N;
char C;
char nextC;
int beedslen = 1;

int main() {
	scanf("%d", &N);
	cin >> C;

	if (N == 1) {
		printf("%d", N);
	}
	else {
		N--;
		while (N > 0) {
			cin >> nextC;
			if ( ( ( (C == 'R') && (nextC == 'R') ) || ( (C == 'R') && (nextC == 'V') ) ) || ( (C == 'B') && (nextC == 'B') || ( (C == 'B') || (nextC == 'V') ) ) ) {

			}
			else beedslen++;

			N--;
			C = nextC;
		}
	}
	printf("%d", beedslen);
}