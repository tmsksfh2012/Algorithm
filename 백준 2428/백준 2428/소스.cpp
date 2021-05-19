#include<stdio.h>
#include<algorithm>
using namespace std;

int fileSize[100010];
long long cnt = 0;
int n;

//Point 오름차순이므로 right가 비교 횟수가 된다
int getDistance(int start, int left, int right) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (fileSize[mid] * 0.9 <= fileSize[start])
			left = mid + 1;
		else
			right = mid;
	}
	return right - 1;
}//upperbound를 찾고, distance를 구하는 함수

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