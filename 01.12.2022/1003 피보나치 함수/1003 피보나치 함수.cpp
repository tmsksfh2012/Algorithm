#include <iostream>
#define endl "\n"
using namespace std;

int T{};
int dp[41] = { 0,1, };

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return dp[n];
    else if(dp[n] == 0)
        dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

	cin >> T;

    while (T--) {
        int N{};

        cin >> N;
        if (N == 0)
            cout << 1 << " " << 0 << endl;
        else
            cout << fibonacci(N - 1) << " " << fibonacci(N) << endl;
    }
}