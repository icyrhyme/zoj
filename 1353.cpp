#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
#define MAXN 300
using namespace std;
long long dp[MAXN][MAXN];
int main() {
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	for(int i = 2; i < MAXN; ++i) {
		dp[i][i] = 1;
		if(i % 2 == 0)
			dp[i][i / 2] = 1;
		for(int j = 1; j < (i + 1) / 2; ++j) {
			dp[i][j] = 0;
			for(int k = j; k <= i - 2 * j; ++k)
				dp[i][j] += dp[i - 2 * j][k];
		}
	}
	long long cnt[MAXN];
	for(int i = 0; i < MAXN; ++i) {
		cnt[i] = 0;
		for(int j = 1; j < MAXN; ++j)
			cnt[i] += dp[i][j];
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		assert(n < MAXN);
		printf("%d %lld\n", n, cnt[n]);
	}
	return 0;
}
