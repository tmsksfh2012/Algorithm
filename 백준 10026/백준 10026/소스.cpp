#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, fir, sec;
bool chk;
string Map1[101];
string Map2[101];

int dfs(int y, int x) {

}

int main() {
	cin >> N;
	
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		Map1[i] = tmp;
		for (int j = 0; j < N; j++) {
			if (tmp[j] == 'G') tmp[j] = 'R';
		}
		Map2[i] = tmp;
	}
	dfs(0, 0)
}