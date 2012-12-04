#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 256
#define INF 1000000000
using namespace std;
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		int a[MAXN], dis[MAXN][MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				dis[i][j] = INF;
			for(int k = i; k < n; ++k) {
				int sum = 0;
				for(int j = i; j <= k; ++j)
					sum += a[k] - a[j];
				for(int j = k; j < n; ++j) {
					sum += a[j] - a[k]; 
					dis[i][j] = min(dis[i][j], sum);
				}
			}
		}
		int dp[MAXN][MAXN];
		for(int i = 0; i <= n; ++i)
			dp[0][i] = INF;
		dp[0][0] = 0;
		for(int i = 1; i <= m; ++i) {
			dp[i][0] = 0;
			for(int j = 1; j <= n; ++j) {
				dp[i][j] = INF;
				for(int k = 0; k < j; ++k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + dis[k][j - 1]);
			}
		}
		printf("Chain %d\n", csnum);
		csnum++;
		printf("Total distance sum = %d\n\n", dp[m][n]);
	}
	return 0;
}
