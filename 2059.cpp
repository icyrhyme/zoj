#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 2048
#define cur(x) ((x)&1)
#define nxt(x) (((x)+1)&1)
using namespace std;
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(n < 0)
			break;
		int dp[2][MAXN];
		memset(dp[0], 0, sizeof(dp[0]));
		for(int i = 0; i < n; ++i)
		{
			int h;
			scanf("%d", &h);
			memset(dp[nxt(i)], 0, sizeof(dp[nxt(i)]));
			for(int j = 0; j < MAXN; ++j)
				if(dp[cur(i)][j] || j == 0)
				{
					dp[nxt(i)][j] = max(dp[nxt(i)][j], dp[cur(i)][j]);
					int diff = abs(j - h);
					dp[nxt(i)][diff] = max(dp[nxt(i)][diff], dp[cur(i)][j] + h);
					diff = j + h;
					dp[nxt(i)][diff] = max(dp[nxt(i)][diff], dp[cur(i)][j] + h);
				}
		}
		if(dp[cur(n)][0])
			printf("%d\n", dp[cur(n)][0] >> 1);
		else
			printf("Sorry\n");
	}
	return 0;
}
