#include <cstdio>
#include <algorithm>
#define MAXN 1024
#define MAXH 1024
#define INF 1000000000
using namespace std;
int n;
int dp[MAXN][MAXH];
int pre[MAXN][MAXH];
int a[MAXN];
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d", &n);
		int sum = 0;
		dp[0][0] = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			fill(dp[i + 1], dp[i + 1] + sum + a[i] + 1, INF);
			for(int j = 0; j <= sum; ++j) {
				if(max(j + a[i], dp[i][j]) < dp[i + 1][j + a[i]]) {
					dp[i + 1][j + a[i]] = max(j + a[i], dp[i][j]);
					pre[i + 1][j + a[i]] = j;
				}
				if(j - a[i] >= 0 && dp[i][j] < dp[i + 1][j - a[i]]) {
					dp[i + 1][j - a[i]] = dp[i][j];
					pre[i + 1][j - a[i]] = j;
				}	
			}
			sum += a[i];
		}
		if(dp[n][0] == INF) {
			printf("IMPOSSIBLE\n");
		}
		else {
			char ans[MAXN];
			int k = 0;
			for(int i = n, j = 0; i != 0; j = pre[i][j], --i) {
				int p = pre[i][j];
				if(p < j) {
					ans[k++] = 'U';
				}
				else {
					ans[k++] = 'D';
				}
			}	
			reverse(ans, ans + k);
			ans[k] = '\0';
			puts(ans);
		}
	}
	return 0;
}
