#include <stdio.h>
#define MAXN 105
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n, m;
char mp[MAXN][MAXN];
int dp[MAXN + MAXN][MAXN][MAXN];
int dj[4] = {0, 1, 0, 1};
int dk[4] = {0, 0, 1, 1};
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d%d", &m, &n);
		int i, j, k, d;
		for(i = 0; i < n; ++i)
			scanf("%s", mp[i]);
		for(i = 0; i < n + m - 1; ++i)
			for(j = 0; j < m; ++j)
				for(k = 0; k < m; ++k)
					dp[i][j][k] = -1;
		if(mp[0][0] == '*')
			dp[0][0][0] = 1;
		else
			dp[0][0][0] = 0;
		for(i = 0; i < n + m - 2; ++i) {
			int le = max(i - n + 1, 0), ri = min(i, m - 1);
			for(j = le; j <= ri; ++j) {
				for(k = le; k <= ri; ++k) {
					if(dp[i][j][k] == -1)
						continue;
					for(d = 0; d < 4; ++d) {
						int nj = j + dj[d];
						int nk = k + dk[d];
						int nle = max(i + 1 - n + 1, 0);
						int nri = min(i + 1, m - 1);
						if(nj >= nle && nj <= nri && nk >= nle && nk <= nri
								&& mp[i + 1 - nj][nj] != '#' && mp[i + 1 - nk][nk] != '#') {
							int val = dp[i][j][k];
							if(mp[i + 1 - nj][nj] == '*')
								++val;
							if(mp[i + 1 - nk][nk] == '*' && nj != nk)
								++val;
							//printf("%d %d:%c, %d %d:%c\n", i + 1 - nj, nj, mp[i + 1 - nj][nj], i + 1 - nk, nk, mp[i + 1- nk][nk]);
							dp[i + 1][nj][nk] = max(dp[i + 1][nj][nk], val);
							//printf("%d %d %d: %d -> %d %d %d: %d\n", i, j, k, dp[i][j][k], i + 1, nj, nk, dp[i + 1][nj][nk]);
						}
					}
				}
			}
		}
		printf("%d\n", dp[n + m - 2][m - 1][m - 1]);
	}
}
