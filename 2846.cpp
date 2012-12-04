#include <iostream>
using namespace std;
#define MAXN 128
#define INF 0x7fffffff
int main() {
	int n, m, cost[MAXN][MAXN], gain[MAXN][MAXN], dp[MAXN][MAXN];
	bool isValid[MAXN][MAXN];
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &cost[i][j]);
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &gain[i][j]);
		for(int j = 0; j < n; ++j)
			dp[0][j] = gain[0][j] - cost[0][j];
		for(int i = 1; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				int maxVal = -INF;
				for(int k = 0; k < n; ++k)
					maxVal = max(maxVal, dp[i - 1][k] - cost[k][j] + gain[i][j]);
				dp[i][j] = maxVal;
			}
		}
		int ans = -INF;
		for(int i = 0; i < n; ++i)
			ans = max(ans, dp[m - 1][i]);
		printf("%d\n", ans);
	}
	return 0;
}
