#include <iostream>
#include <cstdio>
#define MAXV 1024
#define MAXL 8
#define MAXM 10001
#define MAXD 10
#define INF 2000000000
using namespace std;
int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		int cost[MAXV];
		char str[MAXL];
		fill(cost, cost + MAXV, 0);
		for(int i = 0; i < n; ++i) {
			scanf("%s", str);
			int val = str[0] - '0' + (str[1] - '0') * 10 + (str[2] - '0') * 100;
			scanf("%d", &cost[val]);
		}
		if(m == 1 || m == 2) {
			for(int i = 0; i < m; ++i)
				putchar('0');
			putchar('\n');
			continue;
		}
		int dp[MAXM][MAXD][MAXD], pre[MAXM][MAXD][MAXD];
		for(int i = 0; i < MAXD; ++i)
			for(int j = 0; j < MAXD; ++j) {
				pre[1][i][j] = 0;
				dp[0][i][j] = dp[1][i][j] = 0;
			}
		for(int i = 2; i < m; ++i) {
			for(int j = 0; j < MAXD; ++j)
				for(int k = 0; k < MAXD; ++k) {
					dp[i][j][k] = -INF;
					for(int ii = 0; ii < MAXD; ++ii) {
						int co = cost[ii * 100 + j * 10 + k];
						if(dp[i - 1][ii][j] + co > dp[i][j][k]) {
							dp[i][j][k] = dp[i - 1][ii][j] + co;
							pre[i][j][k] = ii;
						}
					}
				}
		}
		int maxi = 0, maxj = 0;
		for(int j = 0; j < MAXD; ++j)
			for(int i = 0; i < MAXD; ++i) {
				if(dp[m - 1][i][j] > dp[m - 1][maxi][maxj]) {
					maxi = i;
					maxj = j;
				}
			}
		int i, j, k;
		for(k = m - 1, i = maxi, j = maxj; k > 0; --k) {
			putchar(j + '0');
			int newi = pre[k][i][j];
			j = i;
			i = newi;
		}
		putchar(j + '0');
		putchar('\n');
	}
	return 0;
}
