#include <cstdio>
#define MAXN 20
using namespace std;
int cs, dp[1 << MAXN], n, len;
bool dfs(int msk) {
	if(dp[msk] == len)
		return true;
	for(int i = msk; i > 0; i = (i - 1) & msk) {
		if(dp[i] == len && dfs(msk - i)) {
			//printf("%o\n", i);
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &cs);
	while(cs--) {
		int sum = 0, tmp;
		dp[0] = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
			dp[1 << i] = tmp;
		}
		if(sum % 4 != 0) {
			printf("no\n");
			continue;
		}
		len = sum / 4;
		int a, b;
		for(int msk = 1; msk < (1 << n); ++msk) {
			if(msk & (msk - 1)) {
				a = msk & (msk - 1);
				b = msk - a;
				dp[msk] = dp[a] + dp[b];
			}
		}
		if(dfs((1 << n) - 1)) 
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
