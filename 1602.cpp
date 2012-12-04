#include <iostream>
#include <cstdio>
#define MAXN 128
#define INF 1000000000
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a[MAXN], dp[MAXN][MAXN];
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dp[i][j] = INF;
		for(int i = 0; i + 1 < n; ++i)
			dp[i][i + 1] = 0;
		for(int k = 2; k < n; ++k)
			for(int i = 0; i + k < n; ++i) {
				for(int j = i + 1; j < i + k; ++j) {
					int newval = dp[i][j] + dp[j][i + k] + a[i] * a[j] * a[i + k];
					dp[i][i + k] = min(dp[i][i + k], newval);
				}
			}
		printf("%d\n", dp[0][n - 1]);
	}
	return 0;
}
