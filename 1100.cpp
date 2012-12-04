#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 11
#define MAXS (1<<MAXN)
using namespace std;
long long ans[MAXN + 1][MAXN + 1];
long long dp[MAXN + 1][MAXN + 1][MAXS];
int gao() {
	for(int m = 1; m <= MAXN; ++m) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < (1 << m); ++k) {
					dp[i][j + 1][k ^ (1 << j)] += dp[i][j][k];
					if(j < m - 1 && (k & (3 << j)) == 0)
						dp[i][j + 2][k] += dp[i][j][k];
				}
			for(int k = 0; k < (1 << m); ++k)
				dp[i + 1][0][k] = dp[i][m][k];
			ans[i + 1][m] = dp[i][m][0];
		}
	}
}
int main() {
	gao();
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF && n && m) {
		printf("%lld\n", ans[min(n, m)][max(n, m)]);
	}
	return 0;
}
