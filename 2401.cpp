#include <cstdio>
#include <cstring>
#define MAXN 256
int main()
{
	char a[MAXN], b[MAXN], c[MAXN * 2];
	int cs, t = 0;
	scanf("%d", &cs);
	while(t < cs)
	{
		scanf("%s%s%s", a, b, c);
		int asz = strlen(a), bsz = strlen(b), csz = strlen(c);
		bool dp[MAXN][MAXN];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for(int i = 0; i <= asz; ++i)
			for(int j = 0; j <= bsz; ++j)
			{
				if(i - 1 >= 0 && a[i - 1] == c[i + j - 1])
					dp[i][j] |= dp[i - 1][j];
				if(j - 1 >= 0 && b[j - 1] == c[i + j - 1])
					dp[i][j] |= dp[i][j - 1];
			}
		if(dp[asz][bsz])
			printf("Data set %d: yes\n", ++t);
		else
			printf("Data set %d: no\n", ++t);
	}
	return 0;
}
