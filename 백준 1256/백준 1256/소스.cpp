#include <stdio.h>

int main() {
	int comb[201][101];
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	comb[0][0] = 1;

	for(int i = 1; i <= n + m; i++) {
		comb[i][0] = 1; 

		for(int j = 1; j < i && j <= m; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j]; 

			if(comb[i][j] > 1000000000) comb[i][j] = 1000000000; 
		}
		if(i <= m) comb[i][i] = 1; 
	}
	k--; 
	if(comb[n + m][m] <= k) {
		puts("-1");
		return 0; 
	} 
	for(int i = m + n - 1; i >= 0; i--) {
		if(i >= m && comb[i][m] > k) putchar('a');
		else {
			putchar('z'); 
			k -= comb[i][m];
			m--; 
		}
	}
}
