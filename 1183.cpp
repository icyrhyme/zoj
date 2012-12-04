#include <iostream>
#include <cstdio>
#define MAXN 1024
#define INF 0x7fffffff
using namespace std;
int main() {
	int cs;
	scanf("%d", &cs);
	while(cs--) {
		int n;
		int csnum = 1;
		while(scanf("%d", &n) != EOF && n != 0) {
			int l, c, a[MAXN], dp[MAXN][MAXN];
			scanf("%d%d", &l, &c);
			fill(dp[0], dp[0] + n + 1, INF);
			for(int i = 1; i <= n; ++i) {
				fill(dp[i], dp[i] + n + 1, INF);
				scanf("%d", &a[i]);
			}
			dp[0][0] = 0;
			bool flag = false;
			int lecnum = -1, totcost = INF;
			for(int i = 0; i < n; ++i) {
				for(int j = i; j <= n; ++j) {
					if(dp[i][j] == INF)
						continue;
					int sum = 0, cost;
					for(int k = j + 1; k <= n && sum + a[k] <= l; ++k) {
						sum += a[k];
						int t = l - sum;
						if(t == 0)
							cost = 0;
						else if(t >= 1 && t <= 10)
							cost = -c;
						else
							cost = (t - 10) * (t - 10);
						if(dp[i + 1][k] > dp[i][j] + cost)
							dp[i + 1][k] = dp[i][j] + cost;
						if(k == n) {
							lecnum = i + 1;
							if(dp[i + 1][k] < totcost)
								totcost = dp[i + 1][k];
						}
					}
				}
				if(lecnum != -1)
					break;
			}
			if(csnum != 1)
				putchar('\n');
			printf("Case %d:\n\n", csnum);
			printf("Minimum number of lectures: %d\n", lecnum);
			printf("Total dissatisfaction index: %d\n", totcost);
			++csnum;
		}
		if(cs != 0)
			printf("\n");
	}
}
