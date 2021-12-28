#include <iostream>
#define NUM 7980
#define N1 NUM / 15
#define N2 NUM / 28
#define N3 NUM / 19
using namespace std;

// 나머지
int a1{}, a2{}, a3{};

 int main() {
	cin >> a1 >> a2 >> a3;

	int ans = (N1 * 13 * a1 + N2 * 17 * a2 + N3 * 10 * a3) % NUM;

	ans > 0 ? cout << ans : cout << 7980;
}