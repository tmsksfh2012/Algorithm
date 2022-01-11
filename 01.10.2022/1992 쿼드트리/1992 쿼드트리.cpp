#include <iostream>
#include <string>
using namespace std;

int N{};
string mat[65]{};

void __init() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
}

void f(pair<int, int> start, pair<int,int> end) {
	if (start == end)
		cout << mat[start.first][start.second];
	else {
		char state = mat[start.first][start.second];
		for (int i = start.first; i < end.first; i++) {
			for (int j = start.second; j < end.second; j++) {
				if (mat[i][j] == state)
					continue;
				else {
					cout << "(";
					// 좌측 상단
					f({ start.first, start.second },
						{ (start.first + end.first) / 2, (start.second + end.second) / 2 });
					// 우측 상단
					f({ start.first, (start.second + end.second) / 2 },
						{ (start.first + end.first) / 2, end.second });
					// 좌측 하단
					f({ (start.first + end.first) / 2, start.second },
						{ end.first, (start.second + end.second) / 2 });
					// 우측 하단
					f({ (start.first + end.first) / 2, (start.second + end.second) / 2 },
						{ end.first, end.second });
					cout << ")";
					return;
				}
			}
		}
		cout << state;
	}
}

int main() {
	__init();

	cin >> N;

	for (int i{}; i < N; i++)
		cin >> mat[i];

	f({ 0,0 }, { N,N });
}