#include <iostream>
using namespace std;

int main() {
	int num;

	long long pre = 1;
	long long past = 1;

	scanf("%d", &num);

	long long tmp = 0;
	for (int i = 1; i < num; i++) {
		tmp = pre;
		pre += past;
		past = tmp;
	}
	printf("%lld", pre * 2 + past * 2);
}