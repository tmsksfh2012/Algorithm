#include <iostream>
using namespace std;

long long DP[91];
int n;

long long fibo(int n, long long DP[90])
{
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	return DP[n];
}

int main()
{
	cin >> n;
	printf("%lld", fibo(n, DP));
	return 0;
}