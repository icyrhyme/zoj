#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#define MAXL 501
#define MAXN 101
using namespace std;
int dp[2][MAXL][MAXL];
int main() {
	int n;
	int w[3], s[3], d[4];
	int c[3], x[MAXN], y[MAXN];
	int cs = 1;
	while(scanf("%d", &n) && n != 0) {
		for(int i = 0; i < 3; ++i) {
			scanf("%d%d%d", &w[i], &s[i], &d[i]);
			//assert(w[i] != 0 && s[i] != 0);
		}
		for(int i = 0; i < 3; ++i) {
			scanf("%d", &c[i]);
			//assert(c[i] != 0);
		}
		scanf("%d", &d[3]);
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		memset(dp, 0xff, sizeof(dp));
		dp[0][0][0] = 0;
		int maxa = 0, maxb = 0;
		for(int i = 0; i < n; ++i) {
			int cur = (i & 1), nxt = ((i + 1) & 1);
			int nmaxa = maxa, nmaxb = maxb;
			for(int j = 0; j <= maxa; ++j)
				for(int k = 0; k <= maxb; ++k) {
					if(dp[cur][j][k] == -1)
						continue;
					for(int dj = 0, rw1 = x[i], rs1 = y[i]; j + dj < MAXL && rw1 >= 0 && rs1 >= 0; ++dj, rw1 -= w[0], rs1 -= s[0]) {
						for(int dk = 0, rw2 = rw1, rs2 = rs1; k + dk < MAXL && rw2 >= 0 && rs2 >= 0; ++dk, rw2 -= w[1], rs2 -= s[1]) {
							dp[nxt][j + dj][k + dk] = max(dp[nxt][j + dj][k + dk], dp[cur][j][k] + min(rw2 / w[2], rs2 / s[2]));
							//printf("%d %d %d %d %d %d %d\n", i, j, k, dj, dk, dp[cur][j][k], dp[nxt][j + dj][k + dk]);
							nmaxa = max(nmaxa, j + dj);
							nmaxb = max(nmaxb, k + dk);
						}
					}
				}
			maxa = nmaxa;
			maxb = nmaxb;
			memset(dp[cur], 0xff, sizeof(dp[cur]));
		}
		int cur = (n & 1);
		int ans = -1;
		int def = max(0, d[3] - c[0] * d[0] - c[1] * d[1] - c[2] * d[2]);
		for(int j = 0; j <= maxa; ++j)
			for(int k = 0; k <= maxb; ++k) {
				if(dp[cur][j][k] == -1)
					continue;
				int sets = min(min(j / c[0], k / c[1]), dp[cur][j][k] / c[2]);
				int curAns = sets * def;
				curAns += j * d[0] + k * d[1] + dp[cur][j][k] * d[2];
				if(curAns > ans)
					ans = curAns;
			}
		if(cs != 1)
			putchar('\n');
		printf("Case %d: %d\n", cs, ans);
		cs++;
	}
	return 0;
}
