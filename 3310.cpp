#include <iostream>
#define MAXN 1000005
#define INF 0x7fffffff
using namespace std;
int N, a[MAXN], dp[MAXN][2];
int main() {
	while(scanf("%d", &N) != EOF) {
		for(int i = 0; i < N; ++i) {
			scanf("%d", &a[i]);
		}
		dp[0][0] = 0, dp[0][1] = a[0];
		for(int i = 1; i < N; ++i) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		int ans = dp[N - 1][0];
		dp[0][0] = dp[0][1] = 0;
		for(int i = 1; i < N; ++i) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][1] = dp[i - 1][0] + a[i];
		}
		ans = max(ans, max(dp[N - 1][0], dp[N - 1][1]));
		printf("%d\n", ans);
	}
	return 0;
}
