#include <iostream>
#include <cstdio>
#define MAXN 1024
#define MAXL 1024
#define INF 1000000000
using namespace std;
char g[MAXN][MAXL];
int main() {
	int n, len;
	int dp[2 * MAXN][26];
	while(scanf("%d%d", &n, &len) != EOF) {
		if(n == 0 && len == 0)
			break;
		for(int i = 0; i < n; ++i)
			scanf("%s", g[i]);
		int totcost = 0;
		for(int i = 0; i < len; ++i) {
			for(int j = 0; j < n + n; ++j)
				fill(dp[j], dp[j] + 26, INF);
			for(int j = 0; j < n; ++j)
				dp[n + j][g[j][i] - 'A'] = 0;
			for(int j = n - 1; j > 0; --j) {
				int le = j * 2;
				int ri = j * 2 + 1;
				int lmin = INF, rmin = INF;
				for(int k = 0; k < 26; ++k) {
					lmin = min(lmin, dp[le][k]);
					rmin = min(rmin, dp[ri][k]);
					dp[j][k] = min(dp[j][k], dp[le][k] + dp[ri][k]);
				}
				for(int k = 0; k < 26; ++k) {
					dp[j][k] = min(dp[j][k], lmin + dp[ri][k] + 1);
					dp[j][k] = min(dp[j][k], dp[le][k] + rmin + 1);
				}	
			}
			int idx = 0;
			for(int k = 0; k < 26; ++k)
				if(dp[1][k] < dp[1][idx])
					idx = k;
			putchar('A' + idx);
			totcost += dp[1][idx];
		}
		printf(" %d\n", totcost);
	}
	return 0;
}
