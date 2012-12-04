#include <cstdio>
#include <cstring>
#define MAXN 1024
using namespace std;
int main() {
	int n, m, csnum = 1;
	while(scanf("%d%d", &n, &m) != EOF) {
		int dp[MAXN];
		memset(dp, 0, sizeof(int) * (n + 1));
		dp[0] = 1;
		for(int i = 0; i < m; ++i) {
			int w, c;
			scanf("%d%d", &w, &c);
			for(int j = n; j - w >= 0; --j) {
				for(int k = 1; k <= c && j - k * w >= 0; ++k) {
					dp[j] += dp[j - k * w];
				}
			}
		}
		if(csnum != 1)
			putchar('\n');
		printf("%d\n", dp[n]);
		++csnum;
	}
	return 0;
}
