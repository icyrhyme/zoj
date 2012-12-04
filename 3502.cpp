#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#define EPS 1e-12
#define MAXN 11
using namespace std;
int main() {
	int cas, p[MAXN][MAXN];
	double dp[1 << MAXN];
	string ans[1 << MAXN];
	scanf("%d", &cas);
	while(cas--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				scanf("%d", &p[i][j]);
		fill(dp, dp + (1 << n), -1);
		fill(ans, ans + (1 << n), "");
		dp[0] = 0;
		for(int m = 0; m < (1 << n); ++m) {
			for(int i = 0; i < n; ++i) {
				if(m & (1 << i))
					continue;
				int mp = p[i][i];
				for(int j = 0; j < n; ++j)
					if(m & (1 << j))
						mp = max(mp, p[j][i]);
				int nm = m | (1 << i);
				double nv = dp[m] * (1 - mp / 100.0) + (dp[m] + 1) * mp / 100.0;
				string ns = ans[m];
				ns.append(1, 'A' + i);
				if(dp[nm] < nv - EPS || fabs(dp[nm] - nv) <= EPS && ans[nm] > ns) {
					dp[nm] = nv;
					ans[nm] = ns;
				}
			}
		}
		printf("%.2lf\n", dp[(1 << n) - 1]);
		puts(ans[(1 << n) - 1].c_str());
	}
	return 0;
}
