#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;

class roomRes {
public:
	int fir;
	int sec;

	roomRes(int x, int y) : fir(x), sec(y) {}

	bool operator < (roomRes &res) {
		if (sec != res.sec) return sec < res.sec;
		else return fir < res.fir;
	}
};


int main() {
	int ans = 1;
	vector<roomRes> v;

	scanf("%d", &N);

	int firNum, secNum;
	while (N--) {
		scanf("%d %d", &firNum, &secNum);

		v.emplace_back(firNum, secNum);
	}
	sort(v.begin(), v.end());

	int tmp = 0;

	for (int i = 1; i < v.size(); i++) {

		if (v[tmp].sec <= v[i].fir) {
			ans++;
			tmp = i;
		}
	}
	printf("%d", ans);
}