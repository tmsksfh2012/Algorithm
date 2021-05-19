#include <iostream>
#include <algorithm>

using namespace std;

int d[1001] = { 0 };
int p[100001] = { 0 };

int getMaxPrice(int n)
{
	if (n == 0)
		return 0;

	else if (d[n] > 0)           // 이게 없으면 시간 초과됨.
		return d[n];

	for (int i = 1; i <= n; i++)  // 선택가능한 것들 중 max 가격을 선택하기 위한 내부 for문
		d[n] = max(d[n], getMaxPrice(n - i) + p[i]);

	return d[n];
}

int main()
{
	int T;
	cin >> T;

	// 묵음별 가격을 입력받음
	for (int i = 1; i <= T; i++)
		cin >> p[i];

	cout << getMaxPrice(T);
}