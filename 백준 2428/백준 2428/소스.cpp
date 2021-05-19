#include<stdio.h>
#include<algorithm>
using namespace std;

int fileSize[100010];
long long cnt = 0;
int n;

//Point ���������̹Ƿ� right�� �� Ƚ���� �ȴ�
int getDistance(int start, int left, int right) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (fileSize[mid] * 0.9 <= fileSize[start])
			left = mid + 1;
		else
			right = mid;
	}
	return right - 1;
}//upperbound�� ã��, distance�� ���ϴ� �Լ�

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &fileSize[i]);
	sort(fileSize, fileSize + n);
	fileSize[n] = 100000001;

	for (int i = 0; i < n - 1; i++) {
		int dis = getDistance(i, i, n) - i;
		cnt += dis;
	}
	printf("%lld\n", cnt);
}