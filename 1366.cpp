#include <iostream>
#define MAXN 1024
#define MAXC 100005
using namespace std;
int lim;
bool dp[MAXC];
void CompletePack(int c)
{
	for(int i = c; i <= lim; ++i)
		dp[i] |= dp[i - c];
}
void ZeroOnePack(int c)
{
	for(int i = lim; i >= c; --i)
		dp[i] |= dp[i - c];
}
void MultiplePack(int c, int amt)
{
	if(c * amt >= lim)
	{
		CompletePack(c);
		return;
	}
	int k = 1;
	while(k < amt)
	{
		ZeroOnePack(k * c);
		amt -= k;
		k <<= 1;
	}
	ZeroOnePack(amt * c);
}
int main()
{
	int amt[MAXN], c[MAXN], n;
	while(scanf("%d", &lim) != EOF)
	{
		scanf("%d", &n);
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &amt[i], &c[i]);
			if(c[i] && amt[i])
				MultiplePack(c[i], amt[i]);
		}
		int ans;
		for(ans = lim; ans >= 0; --ans)
			if(dp[ans])
				break;
		printf("%d\n", ans);
	}
	return 0;
}
