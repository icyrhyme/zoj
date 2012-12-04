#include <iostream>
#include <cstdio>
#define MAXN 16
#define MAXD 32
#define MAXM 1024
#define INF 1000000000
using namespace std;
int days[MAXN][MAXN], cost[MAXN][MAXN][MAXD];
int dp[MAXM][MAXN];
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j) {
				if(i == j)
					continue;
				scanf("%d", &days[i][j]);
				for(int k = 0; k < days[i][j]; ++k)
					scanf("%d", &cost[i][j][k]);
			}
		for(int i = 0; i <= m; ++i)
			fill(dp[i], dp[i] + n, INF);
		dp[0][0] = 0;
		for(int i = 1; i <= m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dp[i - 1][j] == INF)
					continue;
				for(int k = 0; k < n; ++k) {
					if(k == j)
						continue;
					int c = cost[j][k][(i - 1) % days[j][k]];
					if(c > 0) {
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + c);
					}
				}
			}
		}
		printf("Scenario #%d\n", csnum);
		csnum++;
		if(dp[m][n - 1] == INF)
			printf("No flight possible.\n");
		else
			printf("The best flight costs %d.\n", dp[m][n - 1]);
		putchar('\n');
	}
	return 0;
}
