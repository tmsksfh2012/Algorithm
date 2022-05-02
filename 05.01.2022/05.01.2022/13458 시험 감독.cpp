#include <iostream>
#include <vector>
using namespace std;

// N개의 시험장
int N{};
// 총 필요한 감독관 수
long long SUM{};
// i번 시험장 응시자 수
vector<int> vc_A{};
// 감독관과 부감독관 감시 가능 응시자 수
int B{}, C{};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i{}; i < N; i++) {
		int A{};
		cin >> A;

		vc_A.push_back(A);
	}

	cin >> B >> C;

	SUM += N;

	for (auto num_a : vc_A) {
		int temp = num_a - B;

		if (temp < 0)
			continue;
		else {
			int sub_Master = temp / C;
			if (temp % C > 0)
				sub_Master++;
			SUM += sub_Master;
		}
	}

	cout << SUM;
}