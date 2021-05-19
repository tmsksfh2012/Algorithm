#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;

int main() {
	scanf("%d %d", &N, &L);
	vector<int> v;

	int ans = 0;

	int tmp;
	while (N--) {
		scanf("%d", &tmp);
		v.emplace_back(tmp);
	}
	sort(v.begin(), v.end());

	ans++;
	int min = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] - min > L - 1) {
			min = v[i];
			ans++;
		}
	}

	printf("%d", ans);
}