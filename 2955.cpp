#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 128
#define INF 0x7fffffff
using namespace std;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n, m, a[MAXN];
		int dp[MAXN * MAXN];
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int lim = min(m, a[n - 1] * a[n - 1]);
		for(int i = 0; i <= lim; ++i)
			dp[i] = INF;
		dp[0] = 0;
		for(int i = 0; i < n - 1; ++i)
			for(int j = a[i]; j <= lim; ++j) {
				if(dp[j - a[i]] != INF)
					dp[j] = min(dp[j], dp[j - a[i]] + 1);
			}
		int ans = INF;
		for(int i = lim; i >= 0; --i) {
			if(dp[i] == INF)
				continue;
			if((m - i) % a[n - 1] == 0) {
				ans = min(ans, dp[i] + (m - i) / a[n - 1]);
			}
		}
		if(ans == INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}
