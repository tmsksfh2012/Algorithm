#include<stdio.h>
int ans[1001] = { 0,2 };
int gcd(int, int);
int main()
{
	for (int i = 2; i <= 1000; ++i)
	{
		int n = 0;
		for (int j = 1; j <= i; ++j)
		{
			if (gcd(i, j) == 1)
				++n;
		}
		ans[i] = ans[i - 1] + n;
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		printf("%d\n", ans[N] * 2 - 1);
	}
}
int gcd(int a, int b)
{
	while (a % b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return b;
}
