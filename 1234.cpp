#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXN 5005
#define INF 0x7fffffffffffffff
#define C(i) ((i)&1)
#define P(i) (!((i)&1))
#define LL long long
using namespace std;
inline LL sqr(LL a) {
	return a * a;
}
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int k, n, a[MAXN];
		scanf("%d%d", &k, &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n);
		long long dp[2][MAXN];
		fill(dp[0], dp[0] + n + 1, 0);
		k += 8;
		for(int i = 1; i <= k; ++i) {
			fill(dp[C(i)], dp[C(i)] + n + 1, INF);
			for(int j = n - 3 * i; j >= 0; --j) {
				dp[C(i)][j] = dp[C(i)][j + 1];
				dp[C(i)][j] = min(dp[C(i)][j], dp[P(i)][j + 2] + sqr((LL)a[j + 1] - a[j]));
			}
		}
		printf("%lld\n", dp[C(k)][0]);
	}
	return 0;
}
