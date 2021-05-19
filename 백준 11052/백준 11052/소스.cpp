#include <iostream>
#include <algorithm>

using namespace std;

int d[1001] = { 0 };
int p[100001] = { 0 };

int getMaxPrice(int n)
{
	if (n == 0)
		return 0;

	else if (d[n] > 0)           // �̰� ������ �ð� �ʰ���.
		return d[n];

	for (int i = 1; i <= n; i++)  // ���ð����� �͵� �� max ������ �����ϱ� ���� ���� for��
		d[n] = max(d[n], getMaxPrice(n - i) + p[i]);

	return d[n];
}

int main()
{
	int T;
	cin >> T;

	// ������ ������ �Է¹���
	for (int i = 1; i <= T; i++)
		cin >> p[i];

	cout << getMaxPrice(T);
}