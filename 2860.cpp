#include <iostream>
using namespace std;
int dp[MAXN][MAXN];
int main() {
	int a[MAXN], n, len;
	while(scanf("%d%d", &n, &len) != EOF) {
		a[0] = 0, a[n - 1] = len - 1;
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		n += 2;
		for(int i = 0; i + 1 < n; ++i)
			dp[i][i + 1] = 0;
		for(int j = 2; j < n; ++j) {
			for(int i = 0; i + j < n; ++i) {
				for(int k = i + 1; k < i + j; ++k) {
					dp[i][i + j] = min(dp[i][i + j], dp[i][k] + dp[k][i + j] + a[i + j] - a[i]);
				}
			}
		}
	}
}
