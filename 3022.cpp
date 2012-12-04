#include <iostream>
#define MAXN 32
using namespace std;
int main() {
	int N;
	while(scanf("%d", &N) != EOF) {
		double dp[2][MAXN];
		memset(dp, 0, sizeof(dp));
		dp[0][N] = 1;
		char cmd[MAXN], pre = 'A';
		int cnt = 0;
		while(scanf("%s", cmd) != EOF) {
			if(cmd[0] == 'E')
				break;
			memset(dp[1], 0, sizeof(dp[1]));
			for(int k = 0; k <= N; ++k) {
				double p;
				int t;
				if(cmd[0] == 'W') {
					if(pre == 'W')
						t = cnt;
					else
						t = 0;
					if(N - t <= 0 || k - 1 < 0)
						p = 0;
					else if(N - t - k <= 0)
						p = 1;
					else
						p = 1.0 * k / (N - t);
					dp[1][k - 1] += p * dp[0][k];
					dp[1][k] += (1 - p) * dp[0][k];
				}
				else if(cmd[0] == 'K') {
					if(pre == 'K')
						t = cnt;
					else
						t = 0;
					if(N - t <= 0 || N - k <= 0 || k + 1 > N)
						p = 0;
					else
						p = 1.0 * (N - k) / (N - t);
					dp[1][k + 1] += p * dp[0][k];
					dp[1][k] += (1 - p) * dp[0][k];
				}
			}
			if(cmd[0] == pre)
				++cnt;
			else
				cnt = 1;
			pre = cmd[0];
			for(int i = 0; i <= N; ++i)
				dp[0][i] = dp[1][i];
		}
		//for(int i = 0; i <= N; ++i)
		//	printf("%.2lf\n", dp[0][i]);
		printf("%.2lf\n", dp[0][N]);
	}
	return 0;
}
